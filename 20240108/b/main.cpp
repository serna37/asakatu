#include <bits/stdc++.h>
using namespace std;
int main() {
    int D, N;
    cin >> D >> N;
    int a = powl(100, D);
    int b = 1, c = 0;
    while (true) {
        if (b % 100 != 0) {
            c++;
            if (c == N) {
                cout << b * a << endl;
                break;
            }
        }
        b++;
    }
}
