#include <bits/stdc++.h>
using namespace std;
constexpr long long INF = 1e18;
int main() {
    int N, K;
    cin >> N >> K;
    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
        --P[i];
    }
    long long sum = 0;
    vector<long long> C(N);
    for (int i = 0; i < N; ++i) {
        cin >> C[i];
        sum += C[i];
    }
    int loop = K / N;
    int zan = K % N;
    if (zan == 0) {
        zan = N;
        --loop;
    }
    long long ans = -INF;
    for (int i = 0; i < N; ++i) {
        long long p = i;
        long long tmp = 0;
        for (int j = 0; j < zan; ++j) {
            p = P[p];
            tmp += C[p];
            ans = max(ans, tmp);
        }
    }
    if (sum > 0) {
        ans += sum * loop;
    }
    cout << ans << endl;
}
