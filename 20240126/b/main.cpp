#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    string S = to_string(N);
    sort(S.begin(), S.end());
    int M = S.size();
    int ans = 0;
    do {
        for (int i = 1; i < M; i++) {
            string s1 = S.substr(0, i);
            string s2 = S.substr(i, M);
            if (s1.starts_with('0') or s2.starts_with('0')) {
                continue;
            }
            ans = max(ans, stoi(s1) * stoi(s2));
        }
    } while (next_permutation(S.begin(), S.end()));
    cout << ans << endl;
}
