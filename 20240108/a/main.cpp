#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;
int main() {
    int N;
    cin >> N;
    int ans = INF;
    for (int a = 1; a <= N - 1; a++) {
        int b = N - a;
        string as = to_string(a);
        int am = as.size();
        string bs = to_string(b);
        int bm = bs.size();
        int tmp = 0;
        for (int i = 0; i < am; i++) {
            tmp += as[i] - '0';
        }
        for (int i = 0; i < bm; i++) {
            tmp += bs[i] - '0';
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}
