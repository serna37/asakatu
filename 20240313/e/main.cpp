#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    set<int> st;
    for (int i = 1; i < N; i++) {
        if (S[i - 1] == S[i]) {
            st.insert(i);
        }
    }
    st.insert(N);
    while (Q--) {
        int t, L, R;
        cin >> t >> L >> R;
        L--;
        if (t == 1) {
            if (L != 0) {
                if (st.count(L)) {
                    st.erase(L);
                } else {
                    st.insert(L);
                }
            }
            if (R != N) {
                if (st.count(R)) {
                    st.erase(R);
                } else {
                    st.insert(R);
                }
            }
        }
        if (t == 2) {
            if (*st.upper_bound(L) < R) {
                cout << "No" << endl;
            } else {
                cout << "Yes" << endl;
            }
        }
    }
}
