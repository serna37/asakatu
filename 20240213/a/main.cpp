#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    set<int> st;
    for (int i = 1; i <= (N << 1 | 1); i++) {
        st.insert(i);
    }
    for (int i = 0; i <= N; i++) {
        int b = *st.begin();
        cout << b << endl;
        st.erase(b);
        int a;
        cin >> a;
        st.erase(a);
    }
}
