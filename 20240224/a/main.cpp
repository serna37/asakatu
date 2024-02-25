#include <bits/stdc++.h>
using namespace std;
int main() {
    string S;
    cin >> S;
    int N = S.size();
    if (N == 2) {
        cout << S << endl;
    } else {
        reverse(S.begin(), S.end());
        cout << S << endl;
    }
}
