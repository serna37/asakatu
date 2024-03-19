#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    cout << (abs(N - M) == 9 or abs(N - M) == 1 ? "Yes" : "No") << endl;
}
