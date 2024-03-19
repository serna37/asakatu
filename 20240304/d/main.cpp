#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }
    vector<vector<pair<int, int>>> G(N);
    for (int i = 0; i < N - 1; i++) {
        int A, B;
        cin >> A >> B;
        A--, B--;
        G[A].push_back({B, C[B]});
        G[B].push_back({A, C[A]});
    }
    vector<bool> seen(N, false);
    map<int, int> mp;
    vector<int> ans;
    auto dfs = [&](auto &f, int v, int c) -> void {
        seen[v] = true;
        if (!mp.count(c) or mp[c] == 0) ans.push_back(v);
        mp[c]++;
        // 行きがけ
        for (auto [nv, c] : G[v]) {
            if (seen[nv]) continue;
            f(f, nv, c);
        }
        // 帰りがけ
        mp[c]--;
    };
    dfs(dfs, 0, C[0]);
    sort(ans.begin(), ans.end());
    for (auto &&v : ans) {
        cout << v + 1 << endl;
    }
}
