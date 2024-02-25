#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    vector<int> T(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i] >> T[i];
    }
    map<string, pair<int, int>> mp;
    for (int i = 0; i < N; i++) {
        if (mp.count(S[i]) == 0) {
            mp[S[i]] = {T[i], i};
        } else {
            continue;
        }
    }
    const int INF = 1001001001;
    int ans = INF;
    int mx = -1;
    for (auto &v : mp) {
        if (mx < v.second.first) {
            ans = v.second.second;
            mx = v.second.first;
        }
    }
    cout << ++ans << endl;
}
