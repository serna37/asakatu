#include <bits/stdc++.h>
using namespace std;
template <class T> constexpr T inf = 0;
template <> constexpr int inf<int> = 1001001001;
template <> constexpr long long inf<long long> = 1001001001001001001ll;
int main() {
    int N, K;
    cin >> N >> K;
    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }
    sort(h.begin(), h.end());
    long long ans = inf<long long>;
    for (int i = 0; i <= N - K; i++) {
        ans = min(ans, (long long)h[i + K - 1] - h[i]);
    }
    cout << ans << endl;
}
