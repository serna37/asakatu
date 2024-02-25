#include <bits/stdc++.h>
using namespace std;
int main() {
    int A;
    cin >> A;
    for (long long i = 0; i * i * i <= A; i++) {
        if (i * i * i == A) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}
