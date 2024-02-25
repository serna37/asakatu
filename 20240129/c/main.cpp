#include <bits/stdc++.h>
using namespace std;
int main() {
    int N = 19;
    vector<int> dp(N + 1);
    dp[0] = 100;
    dp[1] = 100;
    dp[2] = 200;
    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    cout << dp[N] << endl;
}
