#include <bits/stdc++.h>
using namespace std;
constexpr long long MOD = 1000000007;
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
int main() {
    int N;
    cin >> N;
    vector<int> T(N);
    for (int i = 0; i < N; i++) {
        cin >> T[i];
    }
    sort(T.begin(), T.end());
    vector<long long> S(N + 1);
    for (int i = 0; i < N; i++) {
        S[i + 1] = S[i] + T[i];
    } // S_i = T_0 + ... + T_i-1 →
    long long sum = 0;
    for (int i = 0; i < N + 1; i++) sum += S[i];
    cout << sum << endl;
    map<int, int> mp;
    for (int i = 0; i < N; i++) {
        mp[T[i]]++;
    }
    long long ans = 1;
    for (auto &&[k, cnt] : mp) {
        ans *= modfact(cnt);
        ans %= MOD;
    }
    cout << ans << endl;
}
