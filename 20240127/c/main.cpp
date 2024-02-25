#include <bits/stdc++.h>
using namespace std;
const long long INF = 1001001001001001001ll;
int main() {
    cout << fixed << setprecision(20);
    double A, B;
    cin >> A >> B;
    auto f = [&](long long x) -> double { return A / sqrt(x + 1) + B * x; };
    long long dx = powl(A / (B * 2), 2.0 / 3) - 1;
    double ans = INF;
    for (long long i = max(dx - 3, 0ll); i <= min(dx + 3, (long long)(A / B));
         i++) {
        ans = min(ans, f(i));
    }
    cout << ans << endl;
}
