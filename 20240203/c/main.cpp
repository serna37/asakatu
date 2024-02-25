#include <bits/stdc++.h>
using namespace std;
int main() {
    string S;
    cin >> S;
    int M = S.size();
    vector<int> idx;
    for (int i = 0; i < M; i++) {
        if (S[i] == 'W') {
            idx.push_back(i);
        }
    }
    int N = idx.size();
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += idx[i] - i;
    }
    cout << ans << endl;
}
