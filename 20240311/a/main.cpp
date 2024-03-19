#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1e9;
int main() {
    int N;
    cin >> N;
    vector<int> W(N);
    for (int i = 0; i < N; i++) cin >> W[i];
    int sum = 0;
    for (int i = 0; i < N; i++) sum += W[i];
    int ans = INF;
    for (int T = 1; T < N; T++) {
        int t1 = 0;
        for (int i = 0; i < T; i++) t1 += W[i];
        int t2 = sum - t1;
        ans = min(ans, abs(t1 - t2));
    }
    cout << ans << endl;
}
