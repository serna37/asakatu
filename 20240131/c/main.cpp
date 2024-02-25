#include <bits/stdc++.h>
using namespace std;
int main() {
    int R, G, B, N;
    cin >> R >> G >> B >> N;
    int ans = 0;
    for (int r = 0; r <= N; r++) {
        int za = N - R * r;
        for (int g = 0; g <= za; g++) {
            int zan = za - G * g;
            if (0 <= zan and zan % B == 0) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
