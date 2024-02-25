#include <bits/stdc++.h>
using namespace std;
template <class T> constexpr T inf = 0;
template <> constexpr int inf<int> = 1001001001;
template <> constexpr long long inf<long long> = 1001001001001001001ll;
int main() {
    long long N;
    cin >> N;
    long long ans = inf<long long>;
    for (long long i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            ans = min(ans, i + N / i - 2);
        }
    }
    cout << ans << endl;
}
