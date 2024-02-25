#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    vector<pair<int, int>> p;
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        p.push_back({A[i], B[i]});
    }
    sort(p.begin(), p.end());
}
