#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, D;
    cin >> N >> D;
    if (N - 1 < 2 * D) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= D; j++) {
            int v = i % N + 1;
            int ev = (i + j) % N + 1;
            cout << v << " " << ev << endl;
        }
    }
}
