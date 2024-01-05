#include <bits/stdc++.h>
using namespace std;
int main() {
    cout << fixed << setprecision(20);
    int N, K;
    cin >> N >> K;
    vector<int> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }
    vector<long double> pE(N);
    for (int i = 0; i < N; i++) {
        pE[i] = (p[i] + 1 * 1.0) / 2;
    }
    vector<long double> ruiseki(N + 1);
    for (int i = 0; i < N; i++) {
        ruiseki[i + 1] = ruiseki[i] + pE[i];
    }
    long double ans = 0;
    for (int i = 0; i < N - K + 1; i++) {
        ans = max(ans, ruiseki[i + K] - ruiseki[i]);
    }
    cout << ans << endl;
}
