#include <bits/stdc++.h>
using namespace std;
int main() {
    string S;
    cin >> S;
    int N = S.size();
    vector<int> ans(N + 1);
    int cnt = 0;
    bool prev = false;
    for (int i = 0; i < N; i++) {
        if (S[i] == '<') {
            if (prev) {
                ans[i] = ans[i - 1] + 1;
            } else {
                ans[i] = 0;
                if (cnt != 0) {
                    for (int j = 1; j <= cnt; j++) {
                        ans[i - j] = max(ans[i - j], ans[i - j + 1] + 1);
                    }
                    cnt = 0;
                }
            }
            prev = true;
        } else {
            if (prev) {
                ans[i] = ans[i - 1] + 1;
            }
            prev = false;
            cnt++;
        }
    }
    if (cnt != 0) {
        for (int i = 1; i <= cnt; i++) {
            ans[N - i] = max(ans[N - i], ans[N - i + 1] + 1);
        }
    }
    if (S.back() == '<') {
        ans[N] = ans[N - 1] + 1;
    }
    long long sum = 0;
    for (int i = 0; i < N + 1; i++) {
        sum += ans[i];
    }
    cout << sum << endl;
}
