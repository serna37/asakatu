#include <bits/stdc++.h>
using namespace std;
/**
 * コンビネーション
 */
template <typename T> T nCk(int n, int k) {
    if (k < 0 || n < k) return 0;
    T ret = 1;
    for (T i = 1; i <= k; ++i) {
        ret *= n--;
        ret /= i;
    }
    return ret;
}
int main() {
    int A, B;
    cin >> A >> B;
    long long K;
    cin >> K;
    int N = A + B;
    string ans = "";
    for (int i = 0; i < N; i++) {
        if (A > 0) {
            long long com = nCk<long long>(A + B - 1, B);
            if (com >= K) {
                ans += "a";
                A--;
            } else {
                ans += "b";
                B--;
                K -= com;
            }
        } else {
            ans += string(B, 'b');
            break;
        }
    }
    cout << ans << endl;
}
