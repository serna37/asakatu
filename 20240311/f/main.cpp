#include <bits/stdc++.h>
using namespace std;
constexpr long long MOD = 1000000007;
/**
 * mod二分累乗
 */
long long modpow(long long a, long long n) {
    long long ans = 1ll;
    while (n > 0) {
        if (n & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        n >>= 1ll;
    }
    return ans;
}
/**
 * 逆元
 * @brief Fermatの小定理
 */
long long modinv(long long a) {
    return modpow(a, MOD - 2);
}
/**
 * mod階乗
 */
vector<long long> mf;
long long modfact(int x) {
    if ((int)mf.size() > x) return mf[x];
    if (mf.empty()) mf.push_back(1);
    for (int i = mf.size(); i <= x; i++) mf.push_back(mf.back() * i % MOD);
    return mf[x];
}
/**
 * modコンビネーション
 */
long long mod_combination(int n, int k) {
    return modfact(n) * modinv(modfact(k)) % MOD * modinv(modfact(n - k)) % MOD;
}
int main() {
    int H, W, A, B;
    cin >> H >> W >> A >> B;
    long long ans = 0;
    for (int i = B; i < W; i++) {
        ans += mod_combination(H - A + i - 1, i) *
               mod_combination(A + W - i - 2, A - 1);
        ans %= MOD;
    }
    cout << ans << endl;
}
