#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N;
    cin >> N;
    vector<int> n;
    for (int i = 0; i < 60; i++) {
        if (N & (1ll << i)) {
            n.push_back(i);
        }
    }
    int M = n.size(); // < 15
    vector<long long> ans;
    for (long long bit = 0; bit < 1ll << M; bit++) {
        long long tmp = 0;
        for (int k = 0; k < M; k++) {
            if (bit & (1ll << k)) {
                tmp |= (1ll << n[k]);
            }
        }
        ans.push_back(tmp);
    }
    for (auto v : ans) {
        cout << v << endl;
    }
}
