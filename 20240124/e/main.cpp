#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<long long> S(n + 1);
    for (int i = 0; i < n; i++) {
        S[i + 1] = S[i] + a[i];
    }
    long long ans = 0;
    long long ans2 = 0;
    for (int i = 1; i < n; i++) {
        if (S[i] == 0) {
            S[i]++;
            ans++;
        }
        if (S[i] > 0 and S[i + 1] > 0) {
            S[i + 1] = -1;
            ans += S[i + 1] + 1;
        } else if (S[i] < 0 and S[i + 1] < 0) {
            S[i + 1] = 1;
            ans += S[i + 1] + 1;
        }
    }
    cout << ans << endl;
}
