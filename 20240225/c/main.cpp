#include <bits/stdc++.h>
using namespace std;
const vector<int> dx = {0, 1, 0, -1};
const vector<int> dy = {1, 0, -1, 0};
int main() {
    int mx = 1e3 + 1;
    int sy, sx, gy, gx, T, V;
    cin >> sx >> sy >> gx >> gy >> T >> V;
    int n;
    cin >> n;
    // queue<pair<int, int>> q;
    // q.push({sy, sx});
    // vector<vector<int>> dis(mx, vector<int>(mx, -1));
    // dis[sy][sx] = 0;
    // while (!q.empty()) {
    // auto [py, px] = q.front();
    // q.pop();
    // for (int i = 0; i < 4; i++) {
    // int y = py + dy[i];
    // int x = px + dx[i];
    // if (y < 0 or x < 0 or mx <= y or mx <= x) continue;
    // if (dis[y][x] == -1) {
    // dis[y][x] = dis[py][px] + 1;
    // q.push({y, x});
    //}
    //}
    //}
    bool ans = false;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (hypot(sy - y, sx - x) + hypot(x - gx, y - gy) <= T * V) {
            ans = true;
        }
        // if (dis[y][x] <= D) {
        // ans = true;
        //}
    }
    cout << (ans ? "YES" : "NO") << endl;
}
