#include <bits/stdc++.h>
using namespace std;
int main() {
    cout << fixed << setprecision(20);
    int A, B;
    cin >> A >> B;
    if (A > B) {
        swap(A, B);
    }
    double t = 2 / sqrt(3);
    if ((double)A * t < B) {
        cout << (double)A * t << endl;
        return 0;
    }
    double ans = hypot(B, 2 * A - B * sqrt(3));
    cout << ans << endl;
}
