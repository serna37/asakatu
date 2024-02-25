#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, T;
    cin >> N >> T;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    T--;
    set<int> st;
    for (int i = 0; i < N; i++) {
        st.insert(i);
    }
    vector<vector<pair<int, vector<int>>>> dp(
        N + 1, vector<pair<int, vector<int>>>(T + 1, {0, {}}));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= T; j++) {
            dp[i + 1][j] = dp[i][j];
            if (A[i] <= j) {
                int no = dp[i + 1][j].first;
                int use = dp[i][j - A[i]].first + B[i];
                if (use > no) {
                    dp[i + 1][j].first = use;
                    dp[i + 1][j].second.push_back(i);
                }
            }
        }
    }
    int ans = dp[N][T].first;
    for (auto &v : dp[N][T].second) {
        st.erase(v);
    }
    if (!st.empty()) {
        priority_queue<int> q;
        for (auto &v : st) {
            q.push(B[v]);
        }
        if (!q.empty()) {
            int tmp = q.top();
            ans += tmp;
        }
    }
    cout << ans << endl;
}
