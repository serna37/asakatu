#include <bits/stdc++.h>
using namespace std;
int main() {
    int A, B, C;
    cin >> A >> B >> C;
    if (B > C) swap(B, C);
    if (A > B) swap(A, B);
    if (B > C) swap(B, C);
    int ans = (B - A + 1) / 2;
    if ((B - A) & 1) {
        ans++;
    }
    ans += (C - B);
    cout << ans << endl;
}
