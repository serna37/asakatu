#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<vector<char>> S(N, vector<char>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> S[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j >= 0; j--) {
            cout << S[j][i];
        }
        cout << endl;
    }
}
