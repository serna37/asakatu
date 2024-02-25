#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
int main() {
    string S;
    cin >> S;
    set<char> st;
    int N = S.size();
    int tmp = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == ')') continue;
        if (S[i] == '(') {
            i++, tmp++;
            if (S[i] == '(' or S[i] == ')') continue;
            while (i < N and S[i] != ')') {
                if (st.find(S[i]) != st.end()) {
                    cout << "No" << endl;
                    return 0;
                }
                st.insert(S[i]);
                i++;
            }
            st.clear();
        } else {
            st.insert(S[i]);
        }
    }
    if (tmp == 0) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
}
