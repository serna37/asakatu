#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    vector<int> T(N);
    for (int i = 0; i < N; i++) {
        cin >> T[i];
    }
    for (int i = 0; i < 2 * N; i++) {
        T[i % N] = min(T[i % N], T[(i + N - 1) % N] + S[(i + N - 1) % N]);
    }
    for (int i = 0; i < N; i++) {
        cout << T[i] << endl;
    }
}
