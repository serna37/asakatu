#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<int> W(N), V(N), X(M);
    for (int i = 0; i < N; i++) {
        cin >> W[i] >> V[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> X[i];
    }
    for (int i = 0; i < Q; i++) {
        int L, R;
        cin >> L >> R;
        L--;
        R--;
        R++;
        vector<int> B;
        for (int ii = 0; ii < M; ii++) {
            if (L <= ii and ii < R) {
                continue;
            }
            B.push_back(X[ii]);
        }
        int S = B.size();
        vector<vector<int>> dp(S + 1, vector<int>(N + 1));
        for (int ii = 0; ii < S; ii++) {
            for (int k = 0; k <= N; k++) {
                int wi = W[k], vi = V[k];
                if (B[ii] > W[ii]) {
                    dp[ii + 1][k] = dp[ii][k];
                } else {
                    int m = lower_bound(B.begin(), B.end(), W[ii]) - B.begin();
                    dp[ii + 1][k] = max(dp[ii][k], dp[ii][k - m]);
                }
            }
        }
        cout << dp[S][N] << endl;
    }
}
