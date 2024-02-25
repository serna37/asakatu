#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> A(3 * N);
    for (int i = 0; i < 3 * N; i++) {
        cin >> A[i];
    }
    map<int, vector<int>> mp;
    for (int i = 0; i < 3 * N; i++) {
        mp[A[i]].push_back(i + 1);
    }
    map<int, int> tmp;
    for (auto v : mp) {
        tmp[v.second[1]] = v.first;
    }
    vector<int> ans;
    for (auto &v : tmp) {
        ans.push_back(v.second);
    }
    int M = ans.size();
    for (int i = 0; i < M; i++) {
        if (i) {
            cout << " ";
        }
        cout << ans[i];
    }
    cout << endl;
}
