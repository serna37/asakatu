#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    int n = N * 5;
    vector<int> X(n);
    for (int i = 0; i < n; i++) {
        cin >> X[i];
    }
    sort(X.begin(), X.end());
    for (int i = 0; i < N; i++) {
        X[i] = 0;
    }
    for (int i = n - 1; i > n - 1 - N; i--) {
        X[i] = 0;
    }
    cout << fixed << setprecision(20);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += X[i];
    }
    cout << (double)sum / (3 * N) << endl;
}
