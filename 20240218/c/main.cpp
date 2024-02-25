#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    long long S = 0;
    for (int i = 1; i < N; i++) {
        S += A[i];
        S %= MOD;
    }
    long long ans = S + A[0];
    ans %= MOD;
    for (int i = 1; N - i >= 2; i += 2) {
        int a = N - i;
        ans += A[0] * a;
        ans %= MOD;
        ans += S * (a - 2);
        ans %= MOD;
    }
    set<int> st;
    auto itr = st.lower_bound(3);
    if (itr == st.end()) {
    }
    int a = *--st.end() - *itr;
    // for (int i = N - 1; i >= 2; i -= 2) {
    // ans += A[0] * i;
    // ans %= MOD;
    // ans += S * (i - 2);
    // ans %= MOD;
    //}
    cout << ans << endl;
}
