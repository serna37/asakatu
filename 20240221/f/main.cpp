#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<long long> B(N);
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    auto test = [&](long long x) -> bool {
        long long sum = 0;
        for (int i = 0; i < N; i++) {
            sum += upper_bound(B.begin(), B.end(), x / A[i]) - B.begin();
        }
        return sum >= K;
    };
    long long L = 0, R = 1;
    while (!test(R)) R *= 2;
    while (R - L > 1) (test(L + (R - L) / 2) ? R : L) = L + (R - L) / 2;
    cout << R << endl;
}
