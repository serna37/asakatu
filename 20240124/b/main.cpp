#include <bits/stdc++.h>
using namespace std;
int main() {
    int K, N;
    cin >> K >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int> D(N - 1);
    for (int i = 0; i < N - 1; i++) {
        D[i] = A[i + 1] - A[i];
    }
    D.push_back(K - A.back() + A.front());
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += D[i];
    }
    const int INF = 1001001001;
    int ans = INF;
    for (int i = 0; i < N; i++) {
        ans = min(ans, sum - D[i]);
    }
    cout << ans << endl;
}
