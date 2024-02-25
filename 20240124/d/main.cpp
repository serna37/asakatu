#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    string S;
    cin >> N >> S;
    sort(S.begin(), S.end());
    long long ans = 0;
    long long M = powl(10, N);
    for (long long i = 0; i * i <= M; i++) {
        string s = to_string(i * i);
        if (s.size() < S.size()) {
            string pad = string(S.size() - s.size(), '0');
            s += pad;
        }
        sort(s.begin(), s.end());
        if (s == S) {
            ans++;
        }
    }
    cout << ans << endl;
}
