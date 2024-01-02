#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }
    vector<set<int>> S(N);
    for (int i = 0; i < N; i++) {
        S[i].insert(C[i]);
    }
    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (S[a].size() > S[b].size()) {
            swap(S[a], S[b]);
        }
        for (int v : S[a]) {
            S[b].insert(v);
        }
        S[a].clear();
        cout << S[b].size() << endl;
    }
}
