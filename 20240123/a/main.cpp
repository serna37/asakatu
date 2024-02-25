#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> P(N + 1);
    for (int i = 2; i <= N; i++) {
        cin >> P[i];
    }
    int ans = 0;
    int i = N;
    while (i) {
        i = P[i];
        ans++;
    }
    cout << --ans << endl;
}
