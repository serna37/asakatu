#include <bits/stdc++.h>
using namespace std;
vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};
int main() {
    int H, W;
    cin >> H >> W;
    int sx, sy, gx, gy;
    vector<vector<char>> A(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
            if (A[i][j] == 'S') {
                sy = i;
                sx = j;
            }
            if (A[i][j] == 'G') {
                gy = i;
                gx = j;
            }
        }
    }
    queue<pair<int, int>> q;
    q.push({sy, sx});
    vector<vector<int>> d(H, vector<int>(W, -1));
    d[sy][sx] = 0;
    while (!q.empty()) {
        int py = q.front().first;
        int px = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int y = py + dy[i];
            int x = px + dx[i];
            if (y < 0 or x < 0 or H <= y or W <= x) {
                continue;
            }
            if (d[y][x] == -1 and A[y][x] == '.') {
                d[y][x] = d[py][px] + 1;
                q.push({y, x});
            }
        }
    }
    cout << d[gy][gx] << endl;
}
