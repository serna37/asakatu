#include <bits/stdc++.h>
using namespace std;
int main() {
    int x, y;
    cin >> x >> y;
    if (x == 2 or y == 2) {
        cout << "No" << endl;
        return 0;
    }
    if (x == 4 or x == 6 or x == 9 or x == 11) {
        if (y == 4 or y == 6 or y == 9 or y == 11) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else {
        if (y == 4 or y == 6 or y == 9 or y == 11) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
}
