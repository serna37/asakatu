#include <bits/stdc++.h>
using namespace std;
template <class T> constexpr T inf = 0;
template <> constexpr int inf<int> = 1001001001;
template <> constexpr long long inf<long long> = 1001001001001001001ll;
int main() {
    int N, K, P;
    cin >> N >> K >> P;
    vector<vector<int>> A(N, vector<int>(K));
    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
        for (int j = 0; j < K; j++) {
            cin >> A[i][j];
        }
    }
    vector<map<vector<int>, int>> dp(N + 1);
}
