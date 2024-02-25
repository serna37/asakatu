#include <bits/stdc++.h>
using namespace std;
const vector<int> dx = {0, 1, 0, -1};
const vector<int> dy = {1, 0, -1, 0};
int main() {
    int H, W;
    cin >> H >> W;
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    vector<vector<int>> G(H, vector<int>(W, -1));
    G[0][0] = 0;
    int y = 0, x = 0, d = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < a[i]; j++) {
            G[y][x] = i + 1;
            y += dy[d], x += dx[d];
            if (y < 0 or x < 0 or H <= y or W <= x or G[y][x] != -1) {
                y -= dy[d], x -= dx[d];
                d++;
                d %= 4;
                y += dy[d], x += dx[d];
            }
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (j) cout << " ";
            cout << G[i][j];
        }
        cout << endl;
    }
}
