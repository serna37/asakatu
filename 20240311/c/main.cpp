#include <bits/stdc++.h>
using namespace std;
template <class T> constexpr T inf = 0;
template <> constexpr int inf<int> = 1e9;
template <> constexpr long long inf<long long> = 1e18;
/**
 * 辺
 */
template <typename T> struct Edge {
    int from, to;
    T cost;
    int id;
    Edge(int from, int to, T cost = 1, int id = -1)
        : from(from), to(to), cost(cost), id(id){};
};
/**
 * グラフ
 */
template <typename T> struct Graph {
    vector<vector<Edge<T>>> G;
    Graph(int N) : G(N){};
    vector<Edge<T>> operator[](T v) const {
        return G[v];
    }
    int size() const {
        return G.size();
    }
    void add(int from, int to, T cost = 1, int id = -1) {
        G[from].push_back({from, to, cost, id});
    }
};
/**
 * サイクル検出
 * @return サイクルな辺の集合
 */
template <typename T>
vector<Edge<T>> cycle_detect(const Graph<T> &G, bool directed) {
    int sz = G.size();
    vector<bool> seen(sz), finished(sz);
    vector<Edge<T>> history;
    auto dfs = [&](auto &f, int v, const Edge<T> &e) -> int {
        seen[v] = true;
        history.push_back(e);
        for (const auto &ne : G[v]) {
            auto [from, to, id, cost] = ne;
            if (!directed and to == e.from) continue;
            if (finished[to]) continue;
            if (seen[to] and !finished[to]) {
                history.push_back(ne);
                return to;
            }
            int pos = f(f, to, ne);
            if (pos != -1) return pos;
        }
        finished[v] = true;
        history.pop_back();
        return -1;
    };
    auto restruct = [&](int pos) -> vector<Edge<T>> {
        vector<Edge<T>> cycle;
        while (!history.empty()) {
            const Edge<T> &e = history.back();
            cycle.push_back(e);
            history.pop_back();
            if (e.from == pos) break;
        }
        reverse(cycle.begin(), cycle.end());
        return cycle;
    };
    int pos = -1;
    for (int v = 0; v < sz and pos == -1; ++v) {
        if (seen[v]) continue;
        history.clear();
        pos = dfs(dfs, v, Edge<T>({-1, -1, -1, -1}));
        if (pos != -1) return restruct(pos);
    }
    return vector<Edge<T>>();
}
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    Graph<int> G(N);
    for (int i = 0; i < N; i++) {
        G.add(i, A[i] - 1);
    }
    vector<Edge<int>> res = cycle_detect(G, true);
    int n = res.size();
    cout << n << endl;
    set<int> st;
    cout << res[0].from + 1;
    st.insert(res[0].from + 1);
    for (int i = 1; i < n; i++) {
        if (!st.count(res[i].from + 1)) {
            cout << " " << res[i].from + 1;
        }
        st.insert(res[i].from + 1);
    }
    cout << endl;
}
