#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int N = s.size();
    for (int i = 0; i < N; i++) {
        if (s[i] == 'C') {
            ++i;
            while (i < N and s[i] != 'F') ++i;
            if (s[i] == 'F') {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}
