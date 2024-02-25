#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    long long omote = 1;
    long long ura = 1;
    for (int i = 0; i < N - 1; i++) {
        long long t_omo = 0;
        long long t_ura = 0;
        if (A[i] != A[i + 1]) t_omo += omote;
        if (B[i] != A[i + 1]) t_omo += ura;
        if (A[i] != B[i + 1]) t_ura += omote;
        if (B[i] != B[i + 1]) t_ura += ura;
        omote = t_omo;
        omote %= MOD;
        ura = t_ura;
        ura %= MOD;
    }
    long long ans = omote + ura;
    ans %= MOD;
    cout << ans << endl;
}
