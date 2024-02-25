#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, X;
    cin >> N >> X;
    string a;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < N; j++) {
            a += i + 'A';
        }
    }
    cout << a[X - 1] << endl;
    return 0;
    do {
        X--;
        if (X == 0) {
            cout << a << endl;
            return 0;
        }
    } while (next_permutation(a.begin(), a.end()));
}
