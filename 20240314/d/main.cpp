#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<int> a(Q), b(Q), c(Q), d(Q);
    for (int i = 0; i < Q; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--, b[i]--;
    }
    long long ans = 0;
    vector<int> permutation(N);
    auto cal = [&](auto &f, int de, int s, int mi, int mx) -> void {
        if (de == N) {
            // goal
            long long sum = 0;
            for (int i = 0; i < Q; i++) {
                if (permutation[b[i]] - permutation[a[i]] == c[i]) {
                    sum += d[i];
                }
            }
            ans = max(ans, sum);
            return;
        }
        for (int i = mi; i <= mx; i++) {
            permutation[de] = i;
            mi = i;
            f(f, de + 1, s, mi, mx);
        }
    };
    cal(cal, 0, N - 1, 1, M);
    cout << ans << endl;
}
