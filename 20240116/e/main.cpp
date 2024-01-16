#include <bits/stdc++.h>
using namespace std;
int main() {
    int H, W, T;
    cin >> H >> W >> T;
    vector<vector<char>> G(H, vector<char>(W));
    pair<int, int> s;
    pair<int, int> g;
    for (int i = 0; i < H; i++) {
        for (int ii = 0; ii < W; ii++) {
            cin >> G[i][ii];
            if (G[i][ii] == 'S') {
                s = {i, ii};
            }
        }
    }
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};
    queue<pair<pair<int, int>, pair<int, int>>> q;
    vector<pair<int, int>> dist;
    vector<pair<int, int>> used;
    q.push({s, {0, 0}});
    while (!q.empty()) {
        auto a = q.front();
        q.pop();
        auto pos = a.first;
        auto dis = a.second;
        bool anma = false;
        for (auto v : used) {
            anma |= v.first == pos.first and v.second == pos.second;
        }
        if (anma) {
            continue;
        }
        used.push_back(pos);
        for (int i = 0; i < 4; i++) {
            int y = pos.first + dy[i];
            int x = pos.second + dx[i];
            if (x < 0 or y < 0 or W <= x or H <= y) continue;
            if (G[y][x] == 'G') {
                dist.push_back({dis.first, dis.second + 1});
                continue;
            }
            if (G[y][x] == '#') {
                q.push({{y, x}, {dis.first + 1, dis.second}});
            }
            if (G[y][x] == '.') {
                q.push({{y, x}, {dis.first, dis.second + 1}});
            }
        }
    }
    int ans = 0;
    for (auto v : dist) {
        int x = (T - v.second) / v.first;
        ans = max(ans, x);
    }
    cout << ans << endl;
}
