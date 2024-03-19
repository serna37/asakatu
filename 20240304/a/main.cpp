#include <bits/stdc++.h>
using namespace std;
int main() {
    string S;
    cin >> S;
    int w;
    cin >> w;
    int N = S.size();
    for (int i = 0; i < N; i++) {
        if (i % w == 0) {
            cout << S[i];
        }
    }
    cout << endl;
}
