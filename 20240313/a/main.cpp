#include <bits/stdc++.h>
using namespace std;
int main() {
    string S;
    cin >> S;
    int N = S.size();
    vector<long long> A(N);
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        A[i] = (long long)(S[i] - 'A');
        A[i]++;
        ans += A[i] * powl(26, N - 1 - i);
    }
    cout << ans << endl;
}
