#include <bits/stdc++.h>
using namespace std;
const vector<int> dx = {0, 1, 0, -1};
const vector<int> dy = {1, 0, -1, 0};
int main() {
    int N = 4;
    vector<vector<int>> G(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> G[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < 4; k++) {
                int y = i + dy[k];
                int x = j + dx[k];
                if (y < 0 or x < 0 or N <= y or N <= x) continue;
                if (G[i][j] == G[y][x]) {
                    cout << "CONTINUE" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "GAMEOVER" << endl;
}
