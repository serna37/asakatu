#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N, D, P;
    cin >> N >> D >> P;
    long long cnt = 0, sum = 0;
    vector<long long> F(N);
    for (int i = 0; i < N; i++) {
        cin >> F[i];
        if (P < F[i] * D) cnt++;
        sum += F[i];
    }
    if (cnt == 0) {
        cout << sum << endl;
        return 0;
    }
    long long cnt1 = (cnt + D - 1) / D, cnt2 = cnt / D;
    long long ans1 = 0, ans2 = 0;
    ans1 += (long long)cnt1 * P;
    ans2 += (long long)cnt2 * P;
    cnt1 *= D;
    cnt2 *= D;
    sort(F.rbegin(), F.rend());
    vector<long long> A = F;
    for (int i = 0; i < min(cnt1, N); i++) A[i] = 0;
    for (int i = 0; i < min(cnt2, N); i++) F[i] = 0;
    for (int i = 0; i < N; i++) ans1 += A[i];
    for (int i = 0; i < N; i++) ans2 += F[i];
    cout << min(ans1, ans2) << endl;
}
