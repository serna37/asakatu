#include <bits/stdc++.h>
using namespace std;
int main() {
    long long X, K, D;
    cin >> X >> K >> D;
    X = abs(X);
    long long cnt = K - X / D;
    if (cnt < 0) {
        cout << abs(X - K * D) << endl;
        return 0;
    }
    if (X % D == 0) {
        cout << (cnt % 2 == 0 ? 0 : D) << endl;
    } else {
        cout << (cnt % 2 == 0 ? X % D : D - (X % D)) << endl;
    }
}
