#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, Q;
    cin >> N >> Q;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    vector<long long> S(N + 1);
    for (int i = 0; i < N; i++) {
        S[i + 1] = S[i] + A[i];
    }
    while (Q--) {
        long long X;
        cin >> X;
        int cnt = upper_bound(A.begin(), A.end(), X) - A.begin();
        long long L = abs(S[cnt] - (cnt * X));
        int yoriue = A.end() - upper_bound(A.begin(), A.end(), X);
        long long R = S[N] - S[cnt] - (X * yoriue);
        cout << L + R << endl;
    }
}
