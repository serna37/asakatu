#include <bits/stdc++.h>
using namespace std;
int main() {
    string S;
    int A, B, C, D;
    cin >> S >> A >> B >> C >> D;
    int N = S.size();
    for (int i = 0; i < N; i++) {
        if (i == A or i == B or i == C or i == D) cout << '"';
        cout << S[i];
    }
    if (A == N or B == N or C == N or D == N) {
        cout << '"';
    }
    cout << endl;
}
