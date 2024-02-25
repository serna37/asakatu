#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    for (int i = 0; i < N; i++) {
        cout << A[i] + B[i] << endl;
    }
}
