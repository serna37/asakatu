#include <bits/stdc++.h>
using namespace std;
int main() {
    int H, W, K;
    cin >> H >> W >> K;
    vector<vector<char>> G(H, vector<char>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> G[i][j];
        }
    }
    int ans = 0;
    // bit全探索 O(2^N)
    for (int bit = 0; bit < (1 << H); ++bit) {
        for (int bit2 = 0; bit2 < (1 << W); ++bit2) {
            vector<int> h, w;
            for (int k = 0; k < H; ++k) {
                // k番目を使うか
                if (bit & (1 << k)) h.push_back(k);
            }
            for (int k = 0; k < W; ++k) {
                // k番目を使うか
                if (bit2 & (1 << k)) w.push_back(k);
            }
            auto E = G;
            for (auto &&v : h) {
                for (int i = 0; i < W; ++i) {
                    E[v][i] = '.';
                }
            }
            for (auto &&v : w) {
                for (int i = 0; i < H; ++i) {
                    E[i][v] = '.';
                }
            }
            int cnt = 0;
            for (int i = 0; i < H; ++i) {
                for (int j = 0; j < W; ++j) {
                    if (E[i][j] == '#') {
                        ++cnt;
                    }
                }
            }
            if (cnt == K) {
                ++ans;
            }
        }
    }
    cout << ans << endl;
}
