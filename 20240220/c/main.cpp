#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        vector<int> A(3);
        for (int i = 0; i < 3; i++) {
            cin >> A[i];
        }
        sort(A.begin(), A.end());
        int a = A[0], b = A[1], c = A[2];
        if (a == b and b == c) {
            cout << 0 << endl;
            continue;
        }
        int ans = 0;
        if (a != b and b != c and c != a) {
            int d = b - a;
            int e = c - b;
            if (d % 2 != 0 and e % 2 != 0) {
                cout << -1 << endl;
                continue;
            }
            if (d % 2 == 0 and e % 2 == 0) {
                if (d > e) {
                    d = e;
                }
            } else if (d % 2 == 0) {
                d = e;
            }
            ans += d / 2;
            a += ans * 7;
            b += ans * 5;
            c += ans * 3;
        }
        int d = abs(c - a);
        if (d % 6 != 0) {
            cout << -1 << endl;
            continue;
        }
        ans += d / 6 * 2;
        cout << ans << endl;
    }
}
