#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M, L;
    cin >> N >> M >> L;
    vector<int> q(3);
    for (int i = 0; i < 3; i++) {
        cin >> q[i];
    }
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) continue;
            int tate = N / q[i];
            int yoko = M / q[j];
            int takasa = L / q[3 - (i + j)];
            ans = max(ans, tate * yoko * takasa);
        }
    }
    cout << ans << endl;
}
