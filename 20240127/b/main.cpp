#include <bits/stdc++.h>
using namespace std;
int main() {
    string S;
    cin >> S;
    for (int i = 0; i < 6; i++) {
        if (i) {
            cout << " ";
        }
        char a = i + 'A';
        cout << count(S.begin(), S.end(), a);
    }
    cout << endl;
}
