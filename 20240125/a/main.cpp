#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    string s = to_string(N);
    if (s.find('3') != string::npos or N % 3 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
