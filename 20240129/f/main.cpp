#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N, vector<int>(N));
    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        A--, B--;
        G[A][B] = C;
        G[B][A] = C;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                G[j][k] = min(G[j][k], G[j][i] + G[i][k]);
            }
        }
    }
    int K;
    cin >> K;
    for (int i = 0; i < K; i++) {
        int X, Y, Z;
        cin >> X >> Y >> Z;
        X--, Y--;
        G[X][Y] = min(G[X][Y], Z);
        G[Y][X] = min(G[Y][X], Z);
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                G[j][k] = min(G[j][k], G[j][X] + Z + G[Y][k]);
                G[j][k] = min(G[j][k], G[j][Y] + Z + G[X][k]);
            }
        }
        long long ans = 0;
        for (int j = 0; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                ans += G[j][k];
            }
        }
        cout << ans << endl;
    }
}
