#include <bits/stdc++.h>
using namespace std;
template <class T> constexpr T inf = 0;
template <> constexpr int inf<int> = 1001001001;
template <> constexpr long long inf<long long> = 1001001001001001001ll;
int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        if (A[i] > B[i]) cnt++;
    }
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += max(A[i], B[i]);
    }
    if (cnt & 1) {
        int mi = inf<int>;
        for (int i = 0; i < N; i++) {
            mi = min(mi, abs(A[i] - B[i]));
        }
        ans -= mi;
    }
    cout << ans << endl;
}
