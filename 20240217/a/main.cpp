#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<string> S(N), T(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i] >> T[i];
    }
    map<string, string> mp;
    for (int i = 0; i < N; i++) {
        if (mp.count(S[i])) {
            if (mp[S[i]] == T[i]) {
                cout << "Yes" << endl;
                return 0;
            }
        }
        mp[S[i]] = T[i];
    }
    cout << "No" << endl;
}
