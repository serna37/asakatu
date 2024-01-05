#include <bits/stdc++.h>
using namespace std;
int main() {
    string A;
    long long B;
    cin >> A >> B;
    long long ans = B % (long long)A.size();
    if (ans == 0) {
        ans = (long long)A.size();
    }
    char an = A[ans - 1];
    cout << an << endl;
}
