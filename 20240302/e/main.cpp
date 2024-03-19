#include <bits/stdc++.h>
using namespace std;
int main() {
    int H, W, D;
    cin >> H >> W >> D;
    vector<vector<int>> G(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> G[i][j];
            G[i][j]--;
        }
    }
    int N = H * W;
    vector<int> y(N), x(N);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            y[G[i][j]] = i;
            x[G[i][j]] = j;
        }
    }
    vector<int> S(N, 0);
    for (int i = D; i < N; i++) {
        S[i] = S[i - D] + abs(y[i] - y[i - D]) + abs(x[i] - x[i - D]);
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int L, R;
        cin >> L >> R;
        L--, R--;
        cout << S[R] - S[L] << endl;
    }
}
