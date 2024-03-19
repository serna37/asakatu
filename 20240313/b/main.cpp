#include <bits/stdc++.h>
using namespace std;
int main() {
    string X;
    cin >> X;
    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    map<char, char> mp;
    for (int i = 0; i < 26; i++) {
        mp[X[i]] = (char)i + 'a';
    }
    map<string, string> ans;
    for (int i = 0; i < N; i++) {
        string tmp = "";
        for (auto &&v : S[i]) {
            tmp += mp[v];
        }
        ans[tmp] = S[i];
    }
    for (auto &&[k, v] : ans) {
        cout << v << endl;
    }
}
