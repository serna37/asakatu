#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> s(M), c(M);
    for (int i = 0; i < M; i++) {
        cin >> s[i] >> c[i];
        s[i]--;
    }
    int ans = -1;
    for (int i = 0; i < 1000; i++) {
        string S = to_string(i);
        if (S.size() != N) {
            continue;
        }
        bool allmatch = true;
        for (int ii = 0; ii < M; ii++) {
            allmatch &= S[s[ii]] - '0' == c[ii];
        }
        if (allmatch) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}
