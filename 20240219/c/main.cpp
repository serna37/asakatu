#include <bits/stdc++.h>
using namespace std;
template <typename T, typename F> T int_bisearch(T R, T L, const F &test) {
    while (abs(R - L) > 1) {
        T mid = (R + L) / 2;
        (test(mid) ? R : L) = mid;
    }
    return R;
}
int main() {
    int N, M;
    cin >> N >> M;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<long long> B(M);
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    auto cal = [&](long long x) -> bool {
        int acnt = upper_bound(A.begin(), A.end(), x) - A.begin();
        int bcnt = B.end() - lower_bound(B.begin(), B.end(), x);
        return acnt >= bcnt;
    };
    long long R = 1000000001ll, L = 0ll;
    long long ans = int_bisearch(R, L, cal);
    cout << ans << endl;
}
