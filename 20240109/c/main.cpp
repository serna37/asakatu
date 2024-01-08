#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    vector<vector<int>> k(K);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        k[i % K].push_back(a[i]);
    }
    for (int i = 0; i < K; i++) {
        sort(k[i].rbegin(), k[i].rend());
    }
    vector<int> ans;
    for (int i = 0; i < N; i++) {
        ans.push_back(k[i % K].back());
        k[i % K].pop_back();
    }
    sort(a.begin(), a.end());
    if (a == ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
