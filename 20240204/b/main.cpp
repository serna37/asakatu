#include <bits/stdc++.h>
using namespace std;
int main() {
    string S;
    getline(cin, S);
    int N = S.size();
    string white = "LRA";
    vector<string> ans;
    for (int i = 0; i < N; i++) {
        while (i < N and white.find(S[i]) == string::npos) {
            i++;
        }
        if (S[i] == 'L') {
            ans.push_back("<");
        } else if (S[i] == 'R') {
            ans.push_back(">");
        } else if (S[i] == 'A') {
            ans.push_back("A");
        }
    }
    int M = ans.size();
    for (int i = 0; i < M; i++) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << endl;
}
