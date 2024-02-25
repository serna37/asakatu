#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        string S;
        cin >> N >> S;
        int bcnt = 0;
        if (S[N - 1] == 'A') {
            cout << 'A' << endl;
            continue;
        }
        for (int i = 0; i < N; i++) {
            if (S[i] == 'B') bcnt++;
        }
        string pre = string(N - bcnt, 'A');
        string post = string(bcnt, 'B');
        if (bcnt >= 1 and S == pre + post) {
            cout << 'B' << endl;
        } else {
            cout << 'A' << endl;
        }
    }
}
