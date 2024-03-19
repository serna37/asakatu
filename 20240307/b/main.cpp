#include <bits/stdc++.h>
using namespace std;
int main() {
    int L, H;
    cin >> L >> H;
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] < L) {
            cout << L - A[i] << endl;
        } else if (H < A[i]) {
            cout << -1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
}
