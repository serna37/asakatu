#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, X;
    cin >> N >> X;
    vector<int> V(N), P(N);
    for (int i = 0; i < N; i++) {
        cin >> V[i] >> P[i];
    }
    int al = 0;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        al += V[i] * P[i];
        ans++;
        if (al > X * 100) {
            cout << ans << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
