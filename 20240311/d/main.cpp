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
int main() {
    int N, M;
    cin >> N >> M;
    Graph<long long> G(N);
    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        from--, to--;
        long long cost;
        cin >> cost;
        G.add(from, to, cost, i);
    }
    vector<vector<long long>> dis(N, vector<long long>(N, inf<long long>));
    for (int v = 0; v < N; v++) {
        dis[v][v] = 0;
        for (auto &&[from, to, cost, id] : G[v]) {
            dis[v][to] = min(dis[v][to], cost);
        }
    }
    long long ans = 0;
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            if (dis[i][k] == inf<long long>) continue;
            for (int j = 0; j < N; j++) {
                if (dis[k][j] == inf<long long>) continue;
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (dis[i][j] != inf<long long>) ans += dis[i][j];
            }
        }
    }
    cout << ans << endl;
}
