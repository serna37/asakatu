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
    int N;
    cin >> N;
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int C = i;
        int zan = N - C;
        ans += divisors(zan).size();
    }
    cout << ans << endl;
}
