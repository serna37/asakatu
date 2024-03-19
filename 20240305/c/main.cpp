#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<long long> X(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }
    for (int i = 2; i < 1e6; i++) {
        bool alma = true;
        for (int j = 0; j < N; j++) {
            alma &= gcd(X[j], i) != 1;
        }
        if (alma) {
            cout << i << endl;
            return 0;
        }
    }
}
