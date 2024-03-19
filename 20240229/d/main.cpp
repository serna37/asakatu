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
    if (N == 1) {
        cout << A[0] << endl;
        return 0;
    }
    int ans = inf<int>;
    for (int bit = 1; bit < (1 << N); bit++) {
        int sum = 0;
        int tmp = 0;
        int pre = bit & (1 << 0);
        for (int k = 0; k < N; k++) {
            bool now = bit & (1 << k);
            if (pre == now) {
                tmp |= A[k];
            } else {
                sum ^= tmp;
                tmp = A[k];
            }
            pre = now;
        }
        sum ^= tmp;
        ans = min(ans, sum);
    }
    cout << ans << endl;
}
