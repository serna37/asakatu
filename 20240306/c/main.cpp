#include <bits/stdc++.h>
using namespace std;
int main() {
    long long X;
    cin >> X;
    map<long long, long long> mp;
    for (long long i = -1e3; i <= 1e3; i++) {
        mp[i * i * i * i * i] = i;
    }
    for (auto &&[A5, A] : mp) {
        long long B5 = A5 - X;
        if (mp.count(B5)) {
            cout << A << " " << mp[B5] << endl;
            return 0;
        }
    }
}
