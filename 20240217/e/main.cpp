#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n, m, d;
    cin >> n >> m >> d;
    cout << fixed << setprecision(20);
    if (d == 0) {
        cout << (double)(m - 1) / n << endl;
    } else {
        cout << (double)(n - d) * 2 / n / n * (m - 1) << endl;
    }
}
