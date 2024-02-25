#include <bits/stdc++.h>
using namespace std;
template <typename T> struct Edge {
    int from, to;
    T cost;
    int id;
    Edge(int from, int to, T cost = 1, int id = -1)
        : from(from), to(to), cost(cost), id(id){};
};
template <typename T> using Graph = vector<vector<Edge<T>>>;
template <class T> constexpr T inf = 0;
template <> constexpr int inf<int> = 1001001001;
template <> constexpr long long inf<long long> = 1001001001001001001ll;
template <typename T>
pair<vector<T>, vector<int>> dijkstra(const Graph<T> &G, int s) {
    int N = G.size();
    using P = pair<T, int>;
    priority_queue<P, vector<P>, greater<P>> q;
    q.emplace(0, s);
    vector<T> dis(N, inf<T>);
    // dis[s] = 0;
    vector<int> route(N, -1);
    while (!q.empty()) {
        auto [dv, v] = q.top();
        q.pop();
        if (dv > dis[v]) continue;
        for (auto [from, to, cost, id] : G[v]) {
            T c = dv + cost;
            if (dis[to] > c) {
                dis[to] = c;
                q.emplace(dis[to], to);
                route[to] = v;
            }
        }
    }
    return {dis, route};
}
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
        G[from].push_back({from, to, cost, i});
    }
    for (int i = 0; i < N; i++) {
        auto [dis, route] = dijkstra<long long>(G, i);
        long long ans = dis[i];
        if (ans == inf<long long>) ans = -1;
        cout << ans << endl;
    }
}
