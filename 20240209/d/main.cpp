#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;
int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(K);
    for (int i = 0; i < K; i++) {
        cin >> A[i];
    }
    vector<int> L(K + 1), R(K + 1);
    for (int i = 1; i <= K; i++) {
        L[i] = L[i - 1];
        if (i % 2 == 0) {
            L[i] += A[i - 1] - A[i - 2];
        }
    }
    for (int i = K - 1; i >= 0; i--) {
        R[i] = R[i + 1];
        if ((K - i) % 2 == 0) {
            R[i] += A[i + 1] - A[i];
        }
    }
    int ans = INF;
    for (int i = 0; i <= K; i += 2) {
        ans = min(ans, L[i] + R[i]);
    }
    cout << ans << endl;
}
