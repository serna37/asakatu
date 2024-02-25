#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, X;
    cin >> N >> X;
    vector<int> A(N - 1);
    for (int i = 0; i < N - 1; i++) {
        cin >> A[i];
    }
    for (int i = 0; i <= 100; i++) {
        vector<int> B = A;
        B.push_back(i);
        sort(B.begin(), B.end());
        int sumt = reduce(B.begin(), B.end());
        sumt -= B.front();
        sumt -= B.back();
        if (X <= sumt) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
