#include <bits/stdc++.h>
using namespace std;
template <class T> constexpr T inf = 0;
template <> constexpr int inf<int> = 1001001001;
template <> constexpr long long inf<long long> = 1001001001001001001ll;
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<vector<long long>> dp(N + 1,
                                 vector<long long>(N + 1, inf<long long>));
    dp[0][0] = 0;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j < N; j++) {
        }
    }
    cout << dp[N][N] << endl;
}
