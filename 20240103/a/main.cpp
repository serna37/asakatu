#include <bits/stdc++.h>
using namespace std;
int main() {
    string S, T;
    cin >> S >> T;
    bool allmatch = true;
    for (int i = 0; i < (int)S.size(); i++) {
        allmatch &= S[i] == T[i];
    }
    cout << (allmatch ? "Yes" : "No") << endl;
}
