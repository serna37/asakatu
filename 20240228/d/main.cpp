#include <bits/stdc++.h>
using namespace std;
template <typename T> vector<T> divisors(T a) {
    vector<T> ans;
    for (T i = 1; i * i <= a; i++) {
        if (a % i != 0) continue;
        ans.push_back(i);
        if (a / i != i) ans.push_back(a / i);
    }
    return ans;
}
int main() {
    int N, M;
    cin >> N >> M;
    int ans = 0;
    for (auto &&v : divisors(M)) {
        if (N <= M / v) {
            ans = max(ans, v);
        }
    }
    cout << ans << endl;
}
