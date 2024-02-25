#include <bits/stdc++.h>
using namespace std;
struct UnionFind {
  private:
    int N;
    vector<int> par;

  public:
    UnionFind(int N) : N(N), par(N) {
        iota(par.begin(), par.end(), 0);
    }
    int getRoot(const int &i) {
        return par[i] == i ? i : par[i] = getRoot(par[i]);
    }
    void unite(int x, int y) {
        int rx = getRoot(x), ry = getRoot(y);
        if (rx == ry) return;
        par[rx] = ry;
    }
    bool isSameRoot(int x, int y) {
        return getRoot(x) == getRoot(y);
    }
    bool isRoot(int i) {
        return getRoot(i) == i;
    }
    int getRootCnt() {
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (isRoot(i)) cnt++;
        }
        return cnt;
    }
};
const long long INF = 1001001001001001001ll;
int main() {
    int N, M;
    cin >> N >> M;
    UnionFind uf(N);
    bool ok = true;
    vector<vector<pair<long long, int>>> G(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        a--, b--;
        G[a].push_back({b, c});
        uf.unite(a, b);
    }
    if (!ok) {
        cout << "inf" << endl;
        return 0;
    }
    vector<long long> dp(N + 1, -INF);
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        for (auto &v : G[i]) {
            dp[v.first] = max(dp[v.first], dp[i] + v.second);
        }
    }
    cout << dp[N - 1] << endl;
}
