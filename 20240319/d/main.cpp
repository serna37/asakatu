#include <bits/stdc++.h>
using namespace std;
int main() {
    cout << fixed << setprecision(20);
    int N, K;
    cin >> N >> K;
    vector<int> R(N);
    for (int i = 0; i < N; ++i) {
        cin >> R[i];
    }
    sort(R.begin(), R.end());
    double ans = 0;
    for (int i = N - K; i < N; ++i) {
        ans += R[i];
        ans /= 2;
    }
    cout << ans << endl;
}
