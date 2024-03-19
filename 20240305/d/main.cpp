#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, H;
    cin >> N >> H;
    vector<int> a(N), b(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
    }
    int ma = *max_element(a.begin(), a.end());
    priority_queue<pair<int, int>> q;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        if (ma < b[i]) {
            q.push({b[i], i});
            sum += b[i];
        }
    }
    int ans = 0;
    while (sum < H) {
        H -= ma;
        ans++;
    }
    set<int> useid;
    while (!q.empty()) {
        H -= q.top().first;
        useid.insert(q.top().second);
        q.pop();
        ans++;
        if (H <= 0) {
            cout << ans << endl;
            return 0;
        }
    }
    cout << ans << endl;
}
