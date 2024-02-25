#include <bits/stdc++.h>
using namespace std;
int main() {
    int K, T;
    cin >> K >> T;
    int M = 0;
    for (int i = 0; i < T; i++) {
        int a;
        cin >> a;
        M = max(M, a);
    }
    auto divCeil = []<class T>(T a, T b) -> T {
        return a / b + (((a ^ b) > 0 and a % b != 0) ? 1 : 0);
    };
    int D = divCeil(K, 2);
    if (M <= D) {
        cout << 0 << endl;
    } else {
        cout << (K - 1 - (K - M) * 2) << endl;
    }
}
