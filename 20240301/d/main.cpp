#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int> B(M);
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }
    vector<long long> S(N + 1);
    for (int i = 0; i < N; i++) {
        S[i + 1] = S[i] + A[i];
    }
    vector<long long> S2(M + 1);
    for (int i = 0; i < M; i++) {
        S2[i + 1] = S2[i] + B[i];
    }
    int ans = 0;
    for (int a = 0; a < N + 1; a++) {
        if (K < S[a]) continue;
        long long zan = K - S[a];
        int cnt = upper_bound(S2.begin(), S2.end(), zan) - S2.begin();
        ans = max(ans, a + cnt - 1);
    }
    cout << ans << endl;
}
