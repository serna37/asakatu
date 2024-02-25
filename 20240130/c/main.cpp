#include <bits/stdc++.h>
using namespace std;
int main() {
    string S;
    cin >> S;
    bool ok = true;
    deque<char> q;
    int N = S.size();
    for (int i = 0; i < N; i++) {
        q.push_back(S[i]);
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int T;
        cin >> T;
        if (T == 1) {
            ok = !ok;
        }
        if (T == 2) {
            int F;
            char C;
            cin >> F >> C;
            if ((F == 1 and ok) or (F == 2 and !ok)) {
                q.push_front(C);
            }
            if ((F == 2 and ok) or (F == 1 and !ok)) {
                q.push_back(C);
            }
        }
    }
    if (ok) {
        while (!q.empty()) {
            cout << q.front();
            q.pop_front();
        }
    } else {
        while (!q.empty()) {
            cout << q.back();
            q.pop_back();
        }
    }
    cout << endl;
}
