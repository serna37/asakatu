#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    map<int, int> mp;
    for (int i = 0; i < N; i++) {
        mp[A[i]]++;
    }
    vector<int> B;
    for (auto &v : mp) {
        B.push_back(v.first);
    }
    int M = B.size();
    long long ans = 0;
    vector<int> S(M + 1);
    for (int i = 0; i < M; i++) {
        S[i + 1] = S[i] + B[i];
    }
    for (int i = 0; i < M; i++) {
        for (int j = i + 1; j < M; j++) {
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = i + 1; j < M; j++) {
            for (int k = j + 1; k < M; k++) {
                ans += ((long long)mp[B[i]] * mp[B[j]]) * mp[B[k]];
            }
        }
    }
    cout << ans << endl;
}
