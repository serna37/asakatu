#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    vector<long long> S(N + 1);
    for (int i = 0; i < N; i++) {
        S[i + 1] = S[i] + A[i];
    }
    int ans = 1;
    for (int i = N - 1; i >= 1; i--) {
        if (A[i] <= S[i] * 2) {
            ans++;
        } else {
            break;
        }
    }
    cout << ans << endl;
}
