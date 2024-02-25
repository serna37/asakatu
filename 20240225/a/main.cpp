#include <bits/stdc++.h>
using namespace std;
int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    int start = clamp(C, A, B);
    int end = clamp(D, A, B);
    cout << end - start << endl;
}
