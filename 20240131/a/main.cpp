#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(N);
    for (int i = 0; i < N; i++) {
        A[i].push_back(1);
        if (i == 0) {
            continue;
        }
        int M = A[i - 1].size();
        A[i].resize(M + 1);
        if (M == 1) {
            A[i][1] = 1;
            continue;
        }
        for (int j = 1; j < M + 1; j++) {
            if (j == M) {
                A[i][j] = 1;
                continue;
            }
            A[i][j] = A[i - 1][j] + A[i - 1][j - 1];
        }
    }
    for (int i = 0; i < N; i++) {
        int M = A[i].size();
        for (int j = 0; j < M; j++) {
            if (j) {
                cout << " ";
            }
            cout << A[i][j];
        }
        cout << endl;
    }
}
