#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> t(N);
    for (int i = 0; i < N; i++) {
        cin >> t[i];
    }
    int S = reduce(t.begin(), t.end());
    vector<vector<int>> dp(N + 1, vector<int>(S + 1, false));
    dp[0][0] = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= S; j++) {
            if (dp[i][j]) {
                dp[i + 1][j] = true;
                dp[i + 1][j + t[i]] = true;
            }
        }
    }
    const int INF = 1001001001;
    int ans = INF;
    for (int i = 0; i <= S; i++) {
        if (dp[N][i]) {
            ans = min(ans, max(i, S - i));
        }
    }
    cout << ans << endl;
}
