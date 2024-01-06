#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    int kcnt = 0;
    for (int i = 1; i <= N; i++) {
        if (i % K == 0) {
            kcnt++;
        }
    }
    long long ans = 1;
    ans *= kcnt;
    ans *= kcnt;
    ans *= kcnt;
    int k2cnt = 0;
    if (K % 2 == 0) {
        for (int i = 1; i <= N; i++) {
            if (i % K == K / 2) {
                k2cnt++;
            }
        }
    }
    long long ans2 = 1;
    ans2 *= k2cnt;
    ans2 *= k2cnt;
    ans2 *= k2cnt;
    if (K % 2 == 0) {
        cout << ans + ans2 << endl;
    } else {
        cout << ans << endl;
    }
}

