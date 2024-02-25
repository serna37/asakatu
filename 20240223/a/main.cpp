#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        long long L, R;
        cin >> L >> R;
        if (R < L * 2) {
            cout << 0 << endl;
            continue;
        }
        long long c = R - L * 2 + 1;
        long long ans = (c + 1) * c / 2;
        cout << ans << endl;
    }
}
