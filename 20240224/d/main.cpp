#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> G(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> G[i][j];
        }
    }
    int dis = H + W - 1;
    vector<bool> red(dis, false);
    vector<bool> blue(dis, false);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (G[i][j] == 'R') {
                red[i + j] = true;
            }
            if (G[i][j] == 'B') {
                blue[i + j] = true;
            }
        }
    }
    long long ans = 1;
    for (int i = 0; i < dis; i++) {
        int choose = 2;
        if (red[i]) choose--;
        if (blue[i]) choose--;
        ans *= choose;
        ans %= MOD;
    }
    cout << ans << endl;
}
