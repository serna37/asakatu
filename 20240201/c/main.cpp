#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    string s, t;
    cin >> N >> s >> t;
    int ans = 2 * N;
    for (int i = 0; i < N; i++) {
        if (t.starts_with(s.substr(i, N))) {
            ans -= N - i;
            break;
        }
    }
    cout << ans << endl;
}
