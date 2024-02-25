#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<char> r(N);
    for (int i = 0; i < N; i++) {
        cin >> r[i];
    }
    double ans = 0;
    for (int i = 0; i < N; i++) {
        ans += max('E' - r[i], 0);
    }
    cout << fixed << setprecision(20);
    cout << ans / N << endl;
}
