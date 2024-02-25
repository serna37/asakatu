#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;
int main() {
    int N;
    cin >> N;
    vector<int> X(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }
    int ans = INF;
    for (int i = 0; i <= 100; i++) {
        int tmp = 0;
        for (int j = 0; j < N; j++) {
            tmp += pow(abs(X[j] - i), 2);
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}
