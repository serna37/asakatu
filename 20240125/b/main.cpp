#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    set<int> st;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int P;
        cin >> P;
        if (st.empty() or P <= *st.begin()) {
            ans++;
        }
        st.insert(P);
    }
    cout << ans << endl;
}
