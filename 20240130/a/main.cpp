#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, K, M;
    cin >> N >> K >> M;
    vector<int> A(N - 1);
    for (int i = 0; i < N - 1; i++) {
        cin >> A[i];
    }
    int ans = M * N - reduce(A.begin(), A.end());
    if (K < ans) {
        cout << -1 << endl;
    } else {
        if (ans < 0) {
            cout << 0 << endl;
        } else {
            cout << ans << endl;
        }
    }
}
