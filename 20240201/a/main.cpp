#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == "For") ans++;
    }
    cout << (N - ans < ans ? "Yes" : "No") << endl;
}
