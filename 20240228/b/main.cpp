#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int> B(N);
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
        C[i]--;
    }
    map<int, int> acnt;
    for (int i = 0; i < N; i++) {
        acnt[A[i]]++;
    }
    map<int, int> ccnt;
    for (int i = 0; i < N; i++) {
        ccnt[C[i]]++;
    }
    map<int, vector<int>> mp;
    for (int i = 0; i < N; i++) {
        if (acnt.count(B[i])) {
            mp[B[i]].push_back(i);
        }
    }
    long long ans = 0;
    for (auto [b, ids] : mp) {
        int n = ids.size();
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            if (ccnt.count(ids[i])) {
                tmp += ccnt[ids[i]];
            }
        }
        ans += (long long)tmp * acnt[b];
    }
    cout << ans << endl;
}
