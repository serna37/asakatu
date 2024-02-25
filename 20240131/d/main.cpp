#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    int K;
    cin >> s >> K;
    int N = s.size();
    vector<string> t;
    for (int i = 0; i < N; i++) {
        for (int j = 1; j < 6; j++) {
            string ss = s.substr(i, j);
            t.push_back(ss);
        }
    }
    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());
    cout << t[K - 1] << endl;
}
