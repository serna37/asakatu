#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    set<int> s;
    int n = 300;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int a = i, b = j;
            s.insert(4 * a * b + 3 * (a + b));
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (!s.count(S[i])) ans++;
    }
    cout << ans << endl;
}
