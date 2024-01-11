#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    map<int, int> mp;
    for (int i = 0; i < N; i++) {
        int S, C;
        cin >> S >> C;
        mp[S] = C;
    }
    stack<pair<int, int>> sta;
    for (auto v : mp) {
        sta.push(v);
    }
    while (!sta.empty()) {
        auto v = sta.top();
        sta.pop();
        while (v.second / 2 > 0) {
            mp[v.first * 2] += v.second / 2;
            mp[v.first] = v.second % 2;
            sta.push({v.first * 2, mp[v.first * 2]});
        }
    }
    int ans = 0;
    for (auto v : mp) {
        ans += v.second;
    }
    cout << ans << endl;
}
