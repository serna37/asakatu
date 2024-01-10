#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    map<string, int> mp;
    for (int i = 0; i < N; i++) {
        mp[S[i]]++;
    }
    int m = 0;
    string t = "";
    for (auto kv : mp) {
        if (m < kv.second) {
            t = kv.first;
            m = kv.second;
        }
    }
    cout << t << endl;
}
