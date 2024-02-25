#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    int k;
    cin >> s >> k;
    set<string> st;
    int N = s.size() - k + 1;
    for (int i = 0; i < N; i++) {
        string tmp = "";
        for (int j = i; j < i + k; j++) {
            tmp += s[j];
        }
        st.insert(tmp);
    }
    cout << st.size() << endl;
}
