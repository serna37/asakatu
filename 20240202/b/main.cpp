#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    if (B == 0 and C == 0 and A > 0 and D > 0) {
        cout << "No" << endl;
        return 0;
    }
    if (abs(B - C) > 1) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
}
