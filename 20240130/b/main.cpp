#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int V, W, X, Y, Z;
        cin >> V >> W >> X >> Y >> Z;
        int sum = V + W + X + Y + Z;
        if (0 <= sum and sum < 20) {
            ans++;
        }
    }
    cout << ans << endl;
}
