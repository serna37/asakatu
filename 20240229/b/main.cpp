#include <bits/stdc++.h>
using namespace std;
int main() {
    int A, B;
    cin >> A >> B;
    string a = to_string(A);
    string b = to_string(B);
    a += b;
    int e = stoi(a);
    e <<= 1;
    cout << e << endl;
}
