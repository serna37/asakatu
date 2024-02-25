#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.rbegin(), A.rend());
    vector<int> B(3);
    for (int i = 0; i < 3; i++) {
        B[i] = A[i];
    }
    long long ans = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) continue;
            string a = to_string(B[i]);
            a += to_string(B[j]);
            a += to_string(B[3 - i - j]);
            long long sa = stoll(a);
            ans = max(ans, sa);
        }
    }
    cout << ans << endl;
}
