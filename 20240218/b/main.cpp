#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    map<string, int> mp;
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        mp[S]++;
    }
    int mx = 0;
    for (auto [s, c] : mp) {
        mx = max(mx, c);
    }
    vector<string> A;
    for (auto [s, c] : mp) {
        if (c == mx) A.push_back(s);
    }
    sort(A.begin(), A.end());
    for (auto &&v : A) {
        cout << v << endl;
    }
}
