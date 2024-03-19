#include <bits/stdc++.h>
using namespace std;
int main() {
    long long A, B;
    cin >> A >> B;
    if (A < B) {
        swap(A, B);
    }
    long long ans = 0;
    while (B) {
        ans += A / B;
        A %= B;
        swap(A, B);
    }
    cout << --ans << endl;
}
