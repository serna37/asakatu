#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for (int i = 0; i < N - 1; i++) {
        int A, B;
        cin >> A >> B;
        A--, B--;
        G[A].push_back(B);
        G[B].push_back(A);
    }
    int start = 0;
    for (int i = 0; i < N; i++) {
        if ((int)G[i].size() == 1) {
            start = i;
            break;
        }
    }
    queue<int> q;
    vector<int> dis(N, -1);
    dis[start] = 0;
    start = G[start][0];
    q.push(start);
    vector<int> ans;
    ans.push_back((int)G[start].size());
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int nv : G[v]) {
            if (dis[nv] == -1 and (int) G[nv].size() == 2) {
                dis[nv] = dis[v] + 1;
                int nv2 = 0;
                for (int k = 0; k < 2; k++) {
                    if (G[nv][k] != v) nv2 = G[nv][k];
                }
                dis[nv2] = dis[v] + 2;
                int nextRoot = 0;
                for (int l = 0; l < 2; l++) {
                    if (G[nv2][l] != nv) nextRoot = G[nv2][l];
                }
                ans.push_back((int)G[nextRoot].size());
                q.push(nextRoot);
            }
        }
    }
    sort(ans.begin(), ans.end());
    int sz = ans.size();
    for (int i = 0; i < sz; i++) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << endl;
}
