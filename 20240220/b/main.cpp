#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    string S, T;
    cin >> S >> T;
    queue<int> idx;
    for (int i = 0; i < N; i++) {
        if (S[i] != T[i]) idx.push(i);
    }
    int sz = idx.size();
    if (sz & 1) {
        cout << -1 << endl;
        return 0;
    }
    int s = sz / 2, t = sz / 2;
    string ans = "";
    for (int i = 0; i < N; i++) {
        int id = idx.front();
        if (i != id) {
            ans += "0";
            continue;
        }
        idx.pop();
        if (s > 0 and S[i] == '0') {
            ans += '0';
            s--;
            continue;
        }
        if (t > 0 and T[i] == '0') {
            ans += '0';
            t--;
            continue;
        }
        if (s > 0) {
            ans += S[i];
            s--;
        } else {
            ans += T[i];
            t--;
        }
    }
    cout << ans << endl;
}
