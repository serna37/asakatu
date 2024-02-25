#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;
int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            bool vis = true;
            for (int k = 0; k < N; k++) {
                int dis = A[i][k] + A[k][j];
                if (k != i and k != j and dis == A[i][j]) {
                    vis = false;
                }
                if (dis < A[i][j]) {
                    cout << -1 << endl;
                    return 0;
                }
            }
            if (vis) {
                ans += A[i][j];
            }
        }
    }
    cout << ans << endl;
}
