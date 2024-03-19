#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int r, D, x;
    cin >> r >> D >> x;
    for (int i = 0; i < 10; i++) {
        x *= r;
        x -= D;
        cout << x << endl;
    }
}
