#include <bits/stdc++.h>
using namespace std;
const vector<int> dx = {0, 1, 0, -1, 1, -1, 1, -1};
const vector<int> dy = {1, 0, -1, 0, 1, 1, -1, -1};
int main() {
    int N;
    cin >> N;
    vector<vector<char>> A(N, vector<char>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char a;
            cin >> a;
            A[i][j] = a - '0';
        }
    }
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int sy = i, sx = j;
            for (int k = 0; k < 8; k++) {
                long long c = A[i][j];
                for (int l = 1; l < N; l++) {
                    int y = sy + dy[k] * l;
                    int x = sx + dx[k] * l;
                    y = (y + N) % N;
                    x = (x + N) % N;
                    c *= 10;
                    c += A[y][x];
                }
                ans = max(ans, c);
            }
        }
    }
    cout << ans << endl;
}
