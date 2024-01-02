#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int main() {
    int N, M, K, S, T, X;
    cin >> N >> M >> K >> S >> T >> X;
    vector<vector<int>> Graph(N + 1);
    for (int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        Graph[U].push_back(V);
        Graph[V].push_back(U);
    }
    vector<vector<pair<int, int>>> dp(K + 1,
                                      vector<pair<int, int>>(N + 1, {0, 0}));
    dp[0][S].first = 1;
    for (int edge = 0; edge < K; edge++) {
        for (int v = 1; v <= N; v++) {
            if (v == X) {
                swap(dp[edge][v].first, dp[edge][v].second);
            }
            for (int nextv : Graph[v]) {
                dp[edge + 1][nextv].first += dp[edge][v].first;
                dp[edge + 1][nextv].second += dp[edge][v].second;
                dp[edge + 1][nextv].first %= MOD;
                dp[edge + 1][nextv].second %= MOD;
            }
        }
    }
    cout << dp[K][T].first << endl;
}
