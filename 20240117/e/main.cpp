#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, Q;
    cin >> N >> Q;
    vector<vector<char>> G(N, vector<char>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> G[i][j];
        }
    }
    for (int i = 0; i < Q; i++) {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        int ans = 0;
        for (int j = A; j <= C; j++) {
            int t = j % N;
            for (int k = B; k <= D; k++) {
                if (G[t][k % N] == 'B') {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}
