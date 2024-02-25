#include <bits/stdc++.h>
using namespace std;
int main() {
    string S;
    cin >> S;
    int N = S.size();
    deque<char> T;
    bool f = false;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'R') {
            f = !f;
            continue;
        }
        if (T.empty()) {
            T.push_back(S[i]);
            continue;
        }
        if (f) {
            if (T.front() == S[i]) {
                T.pop_front();
                continue;
            }
            T.push_front(S[i]);
        } else {
            if (T.back() == S[i]) {
                T.pop_back();
                continue;
            }
            T.push_back(S[i]);
        }
    }
    int M = T.size();
    if (M == 0) {
        cout << "" << endl;
        return 0;
    }
    if (f) {
        while (!T.empty()) {
            char t = T.back();
            T.pop_back();
            cout << t;
        }
    } else {
        while (!T.empty()) {
            char t = T.front();
            T.pop_front();
            cout << t;
        }
    }
    cout << endl;
}
