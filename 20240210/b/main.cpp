#include <bits/stdc++.h>
using namespace std;
int main() {
    string S;
    cin >> S;
    int N = S.size();
    string T = "";
    for (int i = 0; i < N; i++) {
        if ('0' <= S[i] and S[i] <= '9') {
            T += S[i];
        }
    }
    cout << T << endl;
}
