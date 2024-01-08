#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    long long P, Q, R;
    cin >> P >> Q >> R;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<long long> S(N + 1);
    for (int i = 0; i < N; i++) {
        S[i + 1] = S[i] + A[i];
    }
    set<long long> st;
    for (int i = 0; i <= N; i++) {
        st.insert(S[i]);
    }
    bool ok = false;
    for (int i = 0; i <= N; i++) {
        long long x = S[i];
        long long y = x + P;
        long long z = y + Q;
        long long w = z + R;
        if (st.count(y) == 1 and st.count(z) == 1 and st.count(w) == 1) {
            ok = true;
        }
        // auto yitr = lower_bound(S.begin(), S.end(), y);
        // if (yitr == S.end() or *yitr != y) {
        // continue;
        //}
        // auto zitr = lower_bound(S.begin(), S.end(), z);
        // if (zitr == S.end() or *zitr != z) {
        // continue;
        //}
        // auto witr = lower_bound(S.begin(), S.end(), w);
        // if (witr == S.end() or *witr != w) {
        // continue;
        //}
        // ok = true;
        // break;
    }
    cout << (ok ? "Yes" : "No") << endl;
}
