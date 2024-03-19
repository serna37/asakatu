#include <bits/stdc++.h>
using namespace std;
int main() {
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
    }
    vector<double> T(N);
    for (int i = 0; i < N; ++i) {
        T[i] = (double)A[i] / B[i];
    }
    double sum = 0;
    for (auto &&v : T) sum += v;
    double H = sum / 2;
    double tmp = 0;
    double ans = 0;
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        if (tmp >= H) {
            break;
        }
        tmp += T[i];
        ans += A[i];
        cnt = i;
    }
    if (H - tmp == 0) {
        cout << ans << endl;
    } else {
        ans += (H - tmp) * B[cnt];
        cout << ans << endl;
    }
}
