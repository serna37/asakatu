#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> R(n);
    for (auto &&v : R) {
        cin >> v;
    }
    vector<int> C(n);
    for (auto &&v : C) {
        cin >> v;
    }
    int q;
    cin >> q;
    string ans = "";
    while (q--) {
        int r, c;
        cin >> r >> c;
        r--, c--;
        ans += (R[r] + C[c] >= n + 1 ? "#" : ".");
    }
    cout << ans << endl;
}
