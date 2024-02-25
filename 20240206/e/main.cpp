#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int main() {
    auto mod_pow = [&]<class T>(T a, T n) -> T {
        T ans = 1;
        while (n > 0) {
            if (n & 1) ans = ans * a % MOD;
            a = a * a % MOD;
            n >>= 1ll;
        }
        return ans;
    };
    auto modinv_fermat = [&](long long a) -> long long {
        return mod_pow(a, MOD - 2);
    };
    vector<long long> mf;
    auto modfact = [&](int x) -> long long {
        if ((int)mf.size() > x) return mf[x];
        if (mf.empty()) mf.push_back(1);
        for (int i = mf.size(); i <= x; i++) mf.push_back(mf.back() * i % MOD);
        return mf[x];
    };
    auto mod_combination = [&](int n, int k) -> long long {
        return modfact(n) * modinv_fermat(modfact(k)) % MOD *
               modinv_fermat(modfact(n - k)) % MOD;
    };
    int N;
    string S;
    cin >> N >> S;
    long long ans = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = 2; j < N - i + 1; j++) {
            string s = S.substr(i, j);
            int M = s.size();
            map<char, int> mp;
            for (int k = 0; k < 26; k++) {
                mp[k + 'a'] = 0;
            }
            for (int k = 0; k < M; k++) {
                mp[s[k]]++;
            }
            int q = mp['?'];
            long long tmp = 0;
            for (auto &v : mp) {
                if (v.first == '?') continue;
                tmp += max(M / 2 - v.second, 0);
            }
            if (tmp == 0) continue;
            ans += mod_combination(tmp, q);
            ans %= MOD;
        }
    }
    cout << ans << endl;
}
