#include <bits/stdc++.h>
using namespace std;
template <class T> constexpr T inf = 0;
template <> constexpr int inf<int> = 1001001001;
template <> constexpr long long inf<long long> = 1001001001001001001ll;
int main() {
    int M;
    cin >> M;
    int N = M * 3;
    vector<string> S(3);
    for (int i = 0; i < 3; i++) {
        cin >> S[i];
    }
    int ans = inf<int>;
    // vector<int> A = {0, 1, 2};
    // do {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (i != j and j != k and k != i) {
                    // if (S[A[0]][i] == S[A[1]][j] and S[A[1]][j] ==
                    // S[A[2]][k]) {
                    if (S[0][i % M] == S[1][j % M] and
                        S[1][j % M] == S[2][k % M]) {
                        ans = min(ans, max({i, j, k}));
                    }
                }
            }
        }
    }
    //} while (next_permutation(A.begin(), A.end()));
    if (ans == inf<int>) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}
