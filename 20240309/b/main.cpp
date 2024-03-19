#include <bits/stdc++.h>
using namespace std;
int main() {
    int N = 4;
    vector<vector<char>> G(N, vector<char>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> G[i][j];
        }
    }
    for (int i = N - 1; i >= 0; i--) {
        for (int j = N - 1; j >= 0; j--) {
            if (j != N - 1) cout << " ";
            cout << G[i][j];
        }
        cout << endl;
    }
}
