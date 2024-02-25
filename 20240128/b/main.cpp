#include <bits/stdc++.h>
using namespace std;
int main() {
    string O, E;
    cin >> O >> E;
    int o = O.size();
    int e = E.size();
    string ans = "";
    for (int i = 0; i < e; i++) {
        ans += O[i];
        ans += E[i];
    }
    if (o > e) {
        ans += O[o - 1];
    }
    cout << ans << endl;
}
