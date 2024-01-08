#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    set<string> S1, S2;
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        if (S[0] == '!') {
            S.erase(S.begin());
            S2.insert(S);
        } else {
            S1.insert(S);
        }
    }
    for (string s1 : S1) {
        if (S2.find(s1) != S2.end()) {
            cout << s1 << endl;
            return 0;
        }
    }
    cout << "satisfiable" << endl;
}
