#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        a[i]--;
    }
    int ans = 0, tmp = 0;
    for (int i = 0; i < N; i++) {
        tmp = a[tmp];
        ans++;
        if (tmp == 1) break;
    }
    if (ans == N) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
}
