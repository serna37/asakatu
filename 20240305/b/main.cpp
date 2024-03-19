#include <bits/stdc++.h>
using namespace std;
int main() {
    auto cal = [&](int y, int m, int d) -> int {
        return 365 * y + (y / 4) - (y / 100) + (y / 400) +
               (306 * (m + 1) / 10) + d - 429;
    };
    int y, m, d;
    cin >> y >> m >> d;
    if (m == 1 or m == 2) {
        y -= 1;
        m += 12;
    }
    cout << abs(cal(y, m, d) - cal(2014, 5, 17)) << endl;
}
