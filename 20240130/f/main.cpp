#include <bits/stdc++.h>
using namespace std;
int main() {
    cout << fixed << setprecision(20);
    int N, A, B;
    cin >> N >> A >> B;
    vector<long long> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.rbegin(), v.rend());
    long double mxAve = 0;
    long long mxSum = 0;
    for (int i = A; i <= B; i++) {
        long long tmpSum = 0;
        for (int j = 0; j < i; j++) {
            tmpSum += v[j];
        }
        if (mxSum < tmpSum) {
            mxSum = tmpSum;
        }
        long double tmpAve = 1.0 * tmpSum / i;
        if (mxAve < tmpAve) {
            mxAve = tmpAve;
        }
    }
    cout << mxAve << endl;
    long long ans = 0;
    for (long long bit = 0; bit < 1 << N; bit++) {
        int tmp = __builtin_popcount(bit);
        if (tmp < A or B < tmp) {
            continue;
        }
        long long tmpv = 0;
        for (int k = 0; k < N; k++) {
            if (bit & (1ll << k)) {
                tmpv += v[k];
            }
        }
        long double ta = 1.0 * tmpv / tmp;
        if (ta == mxAve) {
            ans++;
        }
    }
    cout << ans << endl;
}
