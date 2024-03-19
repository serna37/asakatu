#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N, 0);
    while (Q--) {
        int L, R, T;
        cin >> L >> R >> T;
        L--;
        for (int i = L; i < R; i++) {
            A[i] = T;
        }
    }
    for (int i = 0; i < N; i++) {
        cout << A[i] << endl;
    }
}
