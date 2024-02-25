#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        long long a, s;
        cin >> a >> s;
        vector<int> b;
        for (long long i = 0; i < 60; i++) {
            if (a & 1ll << i) {
                continue;
            }
            b.push_back(i);
        }
        int N = b.size();
        vector<long long> c;
        for (long long bit = 0; bit < 1 << N; bit++) {
            long long tmp = a;
            for (int k = 0; k < N; k++) {
                if (bit & (1ll << k)) {
                    tmp |= (1ll << b[k]);
                }
            }
            c.push_back(tmp);
        }
        sort(c.begin(), c.end());
        for (auto &v : c) {
            if (binary_search(c.begin(), c.end(), s - v)) {
                cout << "Yes" << endl;
                break;
            }
        }
        cout << "No" << endl;
    }
}
