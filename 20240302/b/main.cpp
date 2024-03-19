#include <bits/stdc++.h>
using namespace std;
auto islow = [](char c) -> bool { return islower(c) != 0; };
int main() {
    string S;
    cin >> S;
    int N = S.size();
    bool alma = true;
    alma &= S[0] == 'A';
    int cnt = 0, id = 0;
    for (int i = 0; i < N; i++) {
        if (2 <= i and i <= N - 2) {
            if (S[i] == 'C') {
                cnt++;
                id = i;
            }
        }
    }
    alma &= cnt == 1;
    if (!alma) {
        cout << "WA" << endl;
    } else {
        bool ok = true;
        for (int i = 1; i < N; i++) {
            if (i == id) continue;
            ok &= islow(S[i]);
        }
        if (ok) {
            cout << "AC" << endl;
        } else {
            cout << "WA" << endl;
        }
    }
}
