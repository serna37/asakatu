#include <bits/stdc++.h>
using namespace std;
int main() {
    int S, T;
    cin >> S >> T;
    int ans = 0;
    for (int a = 0; a <= 1e2; ++a) {
        for (int b = 0; b <= 1e2; ++b) {
            for (int c = 0; c <= 1e2; ++c) {
                if (a + b + c <= S and a * b * c <= T) {
                    ++ans;
                }
            }
        }
    }
    cout << ans << endl;
}
