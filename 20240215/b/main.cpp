#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    string S;
    cin >> N >> S;
    if (S.find('-') == string::npos) {
        cout << -1 << endl;
        return 0;
    }
    int ans = -1;
    int cur = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == '-') continue;
        cur = i;
        while (i < N and S[cur] == S[i]) i++;
        ans = max(ans, i - cur);
    }
    cout << ans << endl;
}
