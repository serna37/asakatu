#include <bits/stdc++.h>
using namespace std;
int main() {
    long long A, K;
    cin >> A >> K;
    long long MAX = 2e12;
    if (K == 0) {
        cout << MAX - A << endl;
        return 0;
    }
    int ans = 0;
    while (A < MAX) {
        ans++;
        A += (A * K) + 1;
    }
    cout << ans << endl;
}
