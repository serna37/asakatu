#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    int a = N / 5 * 5;
    int b = (N + 5 - 1) / 5 * 5;
    if (b - N > N - a) {
        cout << a << endl;
    } else {
        cout << b << endl;
    }
}
