#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N, X;
    cin >> N >> X;
    vector<long long> x(N);
    for (long long i = 0; i < N; i++) {
        cin >> x[i];
    }
    x.push_back(X);
    sort(x.begin(), x.end());
    vector<long long> D(N);
    for (long long i = 0; i < N; i++) {
        D[i] = x[i + 1] - x[i];
    }
    long long ans = gcd(D[0], D[1]);
    for (long long i = 0; i < N; i++) {
        ans = gcd(ans, D[i]);
    }
    cout << ans << endl;
}
