#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += a[i];
    }
    if (sum % N != 0) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < N; i++) {
            a[i] -= sum / N;
        }
        vector<int> S(N + 1);
        for (int i = 0; i < N; i++) {
            S[i + 1] = S[i] + a[i];
        }
        int ans = N;
        for (int i = 0; i < N; i++) {
            if (S[i] == 0) {
                ans--;
            }
        }
        cout << ans << endl;
    }
}
