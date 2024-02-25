#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    vector<int> t(N);
    for (int i = 0; i < N; i++) {
        cin >> t[i];
    }
    vector<long long> S(N + 1);
    for (int i = 0; i < N; i++) {
        S[i + 1] = S[i] + t[i];
    }
    for (int i = 0; i < N - 3 + 1; i++) {
        if (S[i + 3] - S[i] < K) {
            cout << i + 3 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
