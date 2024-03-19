#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, L;
    cin >> N >> L;
    int ans = 0;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (L <= A[i]) {
            ans++;
        }
    }
    cout << ans << endl;
}
