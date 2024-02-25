#include <bits/stdc++.h>
using namespace std;
const vector<int> dx = {0, 1, 0, -1};
const vector<int> dy = {1, 0, -1, 0};
int main() {
    int N;
    cin >> N;
    vector<vector<int>> ans(N, vector<int>(N, -1));
    int x = 0;
    int y = 0;
    int tmp = 1;
    ans[0][0] = 1;
    for (int i = 0; i < (N - 1) * 2; i++) {
        for (int j = 0; j < (N - 1) - (i - 1) / 2; j++) {
            y += dy[i % 4];
            x += dx[i % 4];
            tmp++;
            ans[y][x] = tmp;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j) {
                cout << " ";
            }
            if (ans[i][j] == -1) {
                cout << 'T';
            } else {
                cout << ans[i][j];
            }
        }
        cout << endl;
    }
}
