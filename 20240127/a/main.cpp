#include <bits/stdc++.h>
using namespace std;
int main() {
    int A, B;
    string S;
    cin >> A >> B >> S;
    int N = S.size();
    for (int i = 0; i < N; i++) {
        if (i != A and S[i] == '-') {
            cout << "No" << endl;
            return 0;
        }
        if (i == A and S[i] != '-') {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
