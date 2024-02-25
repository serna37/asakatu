#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N, A, B;
    cin >> N >> A >> B;
    long long D = B - A;
    if (D % 2 == 0) {
        cout << D / 2 << endl;
        return 0;
    }
    long long M = min(A - 1, N - B) + 1;
    cout << M + (D / 2) << endl;
}
