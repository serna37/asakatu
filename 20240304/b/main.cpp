#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, W;
    cin >> N >> W;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int> B;
    for (int i = 0; i < N; i++) {
        B.push_back(A[i]);
        for (int j = i + 1; j < N; j++) {
            B.push_back(A[i] + A[j]);
            for (int k = j + 1; k < N; k++) {
                B.push_back(A[i] + A[j] + A[k]);
            }
        }
    }
    sort(B.begin(), B.end());
    B.erase(unique(B.begin(), B.end()), B.end());
    // 以下の個数 = より大きい最左のidx
    int cnt = upper_bound(B.begin(), B.end(), W) - B.begin();
    cout << cnt << endl;
}
