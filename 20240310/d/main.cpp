#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    vector<vector<int>> A(N, vector<int>(K, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            cin >> A[i][j];
        }
    }
    vector<int> bit(N, 0);
    while (1) {
        int tmp = 0;
        for (int i = 0; i < N; i++) {
            if (i == 0) {
                tmp = A[i][bit[i]];
            } else {
                tmp ^= A[i][bit[i]];
            }
        }
        if (tmp == 0) {
            cout << "Found" << endl;
            return 0;
        }
        bit[0]++;
        int c = 0;
        while (1) {
            if (bit[c] > K - 1) {
                if (c == N - 1) {
                    cout << "Nothing" << endl;
                    return 0;
                }
                bit[c] = 0;
                c++;
                bit[c]++;
            } else {
                break;
            }
        }
    }
    cout << "Nothing" << endl;
}
