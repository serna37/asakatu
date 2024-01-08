#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    long long ans = 1;
    vector<int> C(N, 0);
    vector<int> P;
    for (int i = 0; i < N; i++) {
        int a = C[A[i]];
        int b = C[A[i] - 1];
        if (A[i] == 0) {
            b = 3;
        }
        ans *= (b - a);
        ans %= MOD;
        C[A[i]]++;
    }
    cout << ans << endl;
}
