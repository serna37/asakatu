#include <bits/stdc++.h>
using namespace std;
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
 * トポロジカルソート
 */
template <typename Graph> vector<int> topological_sort(const Graph &G) {
    int N = G.size();
    vector<int> seen(N), sorted;
    auto dfs = [&](auto &f, int v) -> void {
        seen[v] = 1;
        for (auto [from, to, cost, i] : G[v]) {
            if (!seen[to]) f(f, to);
        }
        sorted.push_back(v);
    };
    for (int i = 0; i < N; i++) {
        if (!seen[i]) dfs(dfs, i);
    }
    reverse(sorted.begin(), sorted.end());
    return sorted;
}
int main() {
    int N;
    cin >> N;
    Graph<int> G(N);
    for (int i = 0; i < N; i++) {
        int C;
        cin >> C;
        for (int j = 0; j < C; j++) {
            int p;
            cin >> p;
            p--;
            G.add(i, p);
        }
    }
    vector<int> seen(N), sorted;
    auto dfs = [&](auto &f, int v) -> void {
        seen[v] = 1;
        for (auto [from, to, cost, i] : G[v]) {
            if (!seen[to]) f(f, to);
        }
        if (v == 0) return;
        sorted.push_back(v);
    };
    dfs(dfs, 0);
    int n = sorted.size();
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << sorted[i] + 1;
        if (i == n - 1) cout << endl;
    }
}
