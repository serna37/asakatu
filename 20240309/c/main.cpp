#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == c and b == d) {
        cout << 0 << endl;
    } else if (a + b == c + d or a - b == c - d or
               abs(a - c) + abs(b - d) <= 3) {
        cout << 1 << endl;
    } else if ((a + b) % 2 == (c + d) % 2 or abs(a - c) + abs(b - d) <= 6 or
               abs((a + b) - (c + d)) <= 3 or abs((a - b) - (c - d)) <= 3) {
        cout << 2 << endl;
    } else {
        cout << 3 << endl;
    }
}
