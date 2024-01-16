#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, x;
    cin >> n >> x;
    cout << min(abs(n - x), abs(1 - x)) << endl;
}
