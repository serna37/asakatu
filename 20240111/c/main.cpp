#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    vector<int> m;
    m.push_back(0);
    for (int i = 0; i < M; i++) {
        m.push_back(A[i]);
    }
    if (A.back() < N) {
        m.push_back(N + 1);
    }
    vector<int> diff;
    for (int i = 0; i < (int)m.size() - 1; i++) {
        int d = m[i + 1] - m[i] - 1;
        if (d > 0) {
            diff.push_back(d);
        }
    }
    int S = diff.size();
    const int INF = 1001001001;
    int k = INF;
    for (int i = 0; i < S; i++) {
        k = min(k, diff[i]);
    }
    auto divCeil = [](int a, int b) -> int {
        return a / b + (((a ^ b) > 0 and a % b != 0) ? 1 : 0);
    };
    int ans = 0;
    for (int i = 0; i < S; i++) {
        ans += divCeil(diff[i], k);
    }
    cout << ans << endl;
}
