#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    string S;
    cin >> N >> S;
    vector<pair<int, int>> A;
    pair<int, int> C = {0, 0};
    A.push_back(C);
    for (int i = 0; i < N; i++) {
        if (S[i] == 'R') {
            C.first++;
        } else if (S[i] == 'L') {
            C.first--;
        } else if (S[i] == 'U') {
            C.second++;
        } else {
            C.second--;
        }
        A.push_back(C);
    }
    auto mst = A;
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    if (mst.size() == A.size()) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}
