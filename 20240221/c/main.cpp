#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
template <typename T> T modpow(T a, T n) {
    T ans = 1;
    while (n > 0) {
        if (n & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        n >>= 1ll;
    }
    return ans;
}
int main() {
    long long N, P;
    cin >> N >> P;
    cout << (P - 1) * modpow(P - 2, N - 1) % MOD << endl;
}
