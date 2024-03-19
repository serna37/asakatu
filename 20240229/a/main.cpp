#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, A, B;
    cin >> N >> A >> B;
    int mx = min(A, B);
    int a = N - (A + B);
    int ans = 0;
    if (a >= 0) {
        ans = 0;
    } else {
        ans = abs(a);
    }
    cout << mx << " " << ans << endl;
}
