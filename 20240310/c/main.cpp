#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    vector<tuple<long long, long long, long long>> T(N);
    for (int i = 0; i < N; i++) {
        T[i] = {A[i] * 2 + B[i], A[i], B[i]};
    }
    sort(T.rbegin(), T.rend());
    long long C = 0;
    for (int i = 0; i < N; i++) {
        C += A[i];
    }
    long long D = 0;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans++;
        D += get<1>(T[i]) + get<2>(T[i]);
        C -= get<1>(T[i]);
        if (C < D) {
            break;
        }
    }
    cout << ans << endl;
}
