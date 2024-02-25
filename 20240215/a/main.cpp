#include <bits/stdc++.h>
using namespace std;
int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> G(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> G[i][j];
        }
    }
    for (int i = 0; i < W; i++) {
        int ans = 0;
        for (int j = 0; j < H; j++) {
            ans += (int)(G[j][i] == '#');
        }
        if (i) cout << " ";
        cout << ans;
    }
    cout << endl;
}
