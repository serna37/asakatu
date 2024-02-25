#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, D, K;
        cin >> N >> D >> K;
        if (K == 1) {
            cout << 0 << endl;
            continue;
        }
        set<int> st;
        for (int i = 0; i < N; i++) {
            st.insert(i);
        }
        int c = 0;
        st.erase(0);
        int cnt = 1;
        while (true) {
            c += D;
            c %= N;
            auto itr = st.lower_bound(c);
            st.erase(itr);
            cnt++;
            if (cnt == K) {
                cout << *itr << endl;
                break;
            }
        }
    }
}
