#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<vector<int>> S(N, vector<int>(N, -1));
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        for (int j = 0; j < A; j++) {
            int x, y;
            cin >> x >> y;
            x--;
            S[i][x] = y;
        }
    }
    int ans = 0;
    for (long long bit = 0; bit < (1ll << N); bit++) {
        vector<vector<int>> use;
        vector<int> okman, ngman;
        for (int k = 0; k < N; k++) {
            // k番目を使うか
            if (bit & (1ll << k)) {
                use.push_back(S[k]);
                okman.push_back(k);
            } else {
                ngman.push_back(k);
            }
        }
        bool alma = true;
        for (auto &&ok : okman) {
            for (auto &&v : use) {
                if (v[ok] == -1) continue;
                alma &= v[ok] == 1;
            }
        }
        for (auto &&ng : ngman) {
            for (auto &&v : use) {
                if (v[ng] == -1) continue;
                alma &= v[ng] == 0;
            }
        }
        if (alma) {
            ans = max(ans, __builtin_popcount(bit));
        }
    }
    cout << ans << endl;
}
