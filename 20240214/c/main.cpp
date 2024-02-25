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
    long long ans = -inf<long long>;
    for (int l = 0; l < N; l++) {
        int tmp = A[l];
        for (int r = l; r < N; r++) {
            if (tmp > A[r]) {
                tmp = A[r];
            }
            ans = max(ans, (long long)(r - l + 1) * tmp);
        }
    }
    cout << ans << endl;
}
