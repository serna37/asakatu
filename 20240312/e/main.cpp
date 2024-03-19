#include <bits/stdc++.h>
using namespace std;
constexpr long long MOD = 998244353;
int main() {
    int N, D;
    cin >> N >> D;
    // DFS
    vector<int> depth(N);
    auto dfs = [&](auto &f, int v, int p, int d) -> void {
        // 行きがけ
        depth[v] = d;
        f(f, (v << 1), v, d + 1);
        f(f, (v << 1 | 1), v, d + 1);
        // 帰りがけ
    };
    dfs(dfs, 1, -1, 0);
}
