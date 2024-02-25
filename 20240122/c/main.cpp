#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    stack<pair<int, int>> s;
    for (int i = 0; i < N; i++) {
        if (s.empty()) {
            s.push({a[i], 1});
            cout << s.size() << endl;
            continue;
        }
        pair<int, int> t = s.top();
        if (t.first == a[i]) {
            s.push({a[i], t.second + 1});
        } else {
            s.push({a[i], 1});
        }
        pair<int, int> n = s.top();
        if (n.first == n.second) {
            for (int j = 0; j < n.second; j++) {
                s.pop();
            }
        }
        cout << s.size() << endl;
    }
}
