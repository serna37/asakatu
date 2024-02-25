#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    vector<int> P(N);
    long long sum = 0, mx = 0;
    int idx = -1;
    for (int i = 0; i < N; i++) {
        cin >> S[i] >> P[i];
        sum += P[i];
        if (mx < P[i]) {
            mx = P[i];
            idx = i;
        }
    }
    if (sum / 2 < mx) {
        cout << S[idx] << endl;
    } else {
        cout << "atcoder" << endl;
    }
}
