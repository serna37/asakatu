#include <bits/stdc++.h>
using namespace std;
int main() {
    string S;
    cin >> S;
    int N = S.size();
    string s = S;
    for (int i = 0; i < N; i++) {
        s = s.erase(s.size() - 1, 1);
        int M = s.size();
        if (M & 1) continue;
        int mid = M >> 1;
        string tmp = "";
        for (int j = 0; j < mid; j++) {
            tmp += s[j];
        }
        string post = "";
        for (int j = mid; j < M; j++) {
            post += s[j];
        }
        if (tmp == post) {
            cout << M << endl;
            return 0;
        }
    }
}
