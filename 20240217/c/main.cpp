#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int Q;
    cin >> Q;
    vector<string> s = {S.substr(0, N), S.substr(N, 2 * N)};
    while (Q--) {
        int T, A, B;
        cin >> T >> A >> B;
        A--, B--;
        if (T == 1) {
            int a = 0, b = 0;
            if (A >= N) {
                A -= N;
                a = 1;
            }
            if (B >= N) {
                B -= N;
                b = 1;
            }
            swap(s[a][A], s[b][B]);
        } else {
            swap(s[0], s[1]);
        }
    }
    cout << s[0] << s[1] << endl;
}
