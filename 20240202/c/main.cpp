#include <bits/stdc++.h>
using namespace std;
int main() {
    int m;
    cin >> m;
    if (m < 100) {
        cout << "00" << endl;
    } else if (m < 1e3) {
        cout << "0" << (m / 100) << endl;
    } else if (m <= 5e3) {
        cout << (m / 100) << endl;
    } else if (m <= 3e4) {
        cout << (m / 1e3) + 50 << endl;
    } else if (m <= 7e4) {
        cout << (m / 1000 - 30) / 5 + 80 << endl;
    } else {
        cout << "89" << endl;
    }
}
