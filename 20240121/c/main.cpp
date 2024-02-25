#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M, H, K;
    cin >> N >> M >> H >> K;
    string S;
    cin >> S;
    map<int, int> xy;
    vector<int> x(M), y(M);
    for (int i = 0; i < M; i++) {
        cin >> x[i] >> y[i];
        xy[x[i]] = y[i];
    }
    pair<int, int> p = {0, 0};
    for (auto &v : S) {
        if (v == 'R') {
            p.first++;
        } else if (v == 'L') {
            p.first--;
        } else if (v == 'U') {
            p.second++;
        } else {
            p.second--;
        }
        H--;
        if (H < 0) {
            cout << "No" << endl;
            return 0;
        }
        if (xy.count(p.first) != 0 and xy[p.first] == p.second) {
            if (H < K) {
                H = K;
            }
        }
    }
    cout << "Yes" << endl;
}
