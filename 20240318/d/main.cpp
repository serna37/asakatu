#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int H, W, N;
    cin >> H >> W >> N;
    int h, w;
    cin >> h >> w;
    map<int, int> mp;
    vector<vector<int>> G(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> G[i][j];
            mp[G[i][j]]++;
        }
    }
    for (int i = 0; i < H - h + 1; i++) {
        for (int j = 0; j < W - w + 1; j++) {
            auto a = mp;
            for (int k = 0; k < h; k++) {
                for (int l = 0; l < w; l++) {
                    --a[G[i + k][j + l]];
                    if (a[G[i + k][j + l]] == 0) {
                        a.erase(G[i + k][j + l]);
                    }
                }
            }
            if (j) cout << " ";
            cout << a.size();
        }
        cout << endl;
    }
}
