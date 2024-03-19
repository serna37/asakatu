#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<string> S, T;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (s.starts_with("!")) {
            S.push_back(s.erase(0, 1));
        } else {
            T.push_back(s);
        }
    }
    sort(T.begin(), T.end());
    for (string s : S) {
        if (binary_search(T.begin(), T.end(), s)) {
            cout << s << endl;
            return 0;
        }
    }
    cout << "satisfiable" << endl;
}
