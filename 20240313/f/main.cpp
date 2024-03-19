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
 * 素集合データ構造 Disjoint-Set
 * @brief 重みなし
 */
struct UnionFind {
  private:
    int N;
    vector<int> dat;
    void build() {
        dat.assign(N, -1);
    }

  public:
    UnionFind(int n = 0) : N(n) {
        build();
    }
    void reset() {
        build();
    }
    int operator[](int x) {
        while (dat[x] >= 0) {
            int pp = dat[dat[x]];
            if (pp < 0) return dat[x];
            x = dat[x] = pp;
        }
        return x;
    }
    long long size(int x) {
        x = (*this)[x];
        return -dat[x];
    }
    bool unite(int x, int y) {
        x = (*this)[x], y = (*this)[y];
        if (x == y) return false;
        if (-dat[x] < -dat[y]) swap(x, y);
        dat[x] += dat[y], dat[y] = x;
        return true;
    }
    vector<vector<int>> groups() {
        vector<vector<int>> ret(N);
        for (int i = 0; i < N; i++) {
            ret[(*this)[i]].emplace_back(i);
        }
        ret.erase(remove_if(begin(ret), end(ret),
                            [&](const vector<int> &v) { return v.empty(); }),
                  end(ret));
        return ret;
    }
};
/**
 * 最小全域木
 */
template <typename T> struct MinSpanTree {
    T cost;
    vector<Edge<T>> edges;
};
/**
 * クラスカル
 * @return 最小全域木
 */
template <typename T>
MinSpanTree<T> Kruskal(vector<Edge<T>> edges, int v_cnt, int N) {
    sort(edges.begin(), edges.end(),
         [](const Edge<T> &a, const Edge<T> &b) { return a.cost < b.cost; });
    UnionFind tree(v_cnt);
    T total = T();
    vector<Edge<T>> es;
    for (auto &&e : edges) {
        if (tree.unite(e.from, e.to)) {
            es.emplace_back(e);
            total += e.cost;
        }
    }
    if (tree.size(0) < N) {
        total = inf<T>;
    }
    return {total, es};
}
int main() {
    int N, M;
    cin >> N >> M;
    vector<long long> X(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }
    vector<long long> Y(N);
    for (int i = 0; i < N; i++) {
        cin >> Y[i];
    }
    vector<int> A(M), B(M);
    vector<long long> Z(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i] >> Z[i];
        A[i]--, B[i]--;
    }
    vector<Edge<long long>> E;
    long long ans = inf<long long>;
    for (int k = 0; k < 4; k++) {
        E.clear();
        for (int i = 0; i < M; i++) {
            E.push_back({A[i], B[i], Z[i]});
        }
        if (k & 1) { // 1, 3
            for (int i = 0; i < N; i++) {
                E.push_back({i, N, X[i]});
            }
        }
        if (k & 2) { // 2, 3
            for (int i = 0; i < N; i++) {
                E.push_back({i, N + 1, Y[i]});
            }
        }
        MinSpanTree<long long> mst = Kruskal(E, N + 2, N);
        ans = min(ans, mst.cost);
    }
    cout << ans << endl;
}
