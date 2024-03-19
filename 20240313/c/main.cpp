#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    sort(S.begin(), S.end());
    do {
        bool alma = true;
        for (int i = 1; i < N; i++) {
            int diff = 0;
            for (int j = 0; j < M; j++) {
                if (S[i - 1][j] != S[i][j]) {
                    diff++;
                }
            }
            alma &= diff == 1;
        }
        if (alma) {
            cout << "Yes" << endl;
            return 0;
        }
    } while (next_permutation(S.begin(), S.end()));
    cout << "No" << endl;
}
