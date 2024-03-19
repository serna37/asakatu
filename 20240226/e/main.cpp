#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    vector<int> L(M);
    for (int i = 0; i < M; i++) {
        cin >> L[i];
    }
    vector<int> D(M);
    for (int i = 0; i < M; i++) {
        cin >> D[i];
    }
    sort(P.begin(), P.end());
    map<int, vector<int>> mp;
    for (int i = 0; i < M; i++) {
        int p = lower_bound(P.begin(), P.end(), L[i]) - P.begin();
        if (p < N) {
            mp[p].push_back(i);
        }
    }
    priority_queue<int> q;
    for (int i = 0; i < N; i++) {
        q.push(0);
    }
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j : mp[i]) {
            q.push(D[j]);
        }
        ans += P[i] - q.top();
        q.pop();
    }
    cout << ans << endl;
}
