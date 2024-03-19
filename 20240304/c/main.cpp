#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= M; i++) {
        dp[0][i] = i;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < M; j++) {
            if (i * j <= K) {
                dp[i + 1][j] = dp[i][j] * j % MOD;
            }
        }
    }
    cout << dp[N][M] << endl;
}
