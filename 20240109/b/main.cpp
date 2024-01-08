#include <bits/stdc++.h>
using namespace std;
int main() {
    int A, V, B, W, T;
    cin >> A >> V >> B >> W >> T;
    int dv = V - W;
    auto divCeil = [](long long a, long long b) -> long long {
        return a / b + (((a ^ b) > 0 and a % b != 0) ? 1 : 0);
    };
    if (dv <= 0) {
        cout << "NO" << endl;
    } else if (divCeil(abs(B - A), dv) <= T) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
