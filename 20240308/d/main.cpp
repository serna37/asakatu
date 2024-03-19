#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<long long> B(N);
    for (int i = 0; i < N; i++) {
        B[i] = A[i] - i;
    }
    map<long long, int> mp;
    for (int i = 0; i < N; i++) {
        mp[B[i]]++;
    }
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        int t = -A[i] - i;
        // ans += (long long)mp[t] * (mp[t] - 1) / 2;
        // mp[t] = 0;
        ans += mp[t];
    }
    cout << ans << endl;
}
