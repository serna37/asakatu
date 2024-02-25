#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> x(N), y(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }
    vector<pair<int, int>> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        X[i] = {x[i], i};
        Y[i] = {y[i], i};
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    int XM = X.back().first - X.front().first;
    int YM = Y.back().first - Y.front().first;
    int s = 0, t = 0;
    if (XM > YM) {
        s = X.back().second;
        t = X.front().second;
    } else {
        s = Y.back().second;
        t = Y.front().second;
    }
    int ans = 0;
    for (int i = 0; i < 2; i++) {
        vector<int> x2, y2;
        for (int j = 0; j < N; j++) {
            if (!(i == 0 and j == s or i == 1 and j == t)) {
                x2.push_back(x[j]);
                y2.push_back(y[j]);
            }
        }
        sort(x2.begin(), x2.end());
        sort(y2.begin(), y2.end());
        ans = max(ans, x2.back() - x2.front());
        ans = max(ans, y2.back() - y2.front());
    }
    cout << ans << endl;
}
