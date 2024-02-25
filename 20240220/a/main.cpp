#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    for (int i = N; i <= 999; i++) {
        int a = i / 100;
        int b = i % 100 / 10;
        int c = i % 10;
        if (a * b == c) {
            cout << i << endl;
            return 0;
        }
    }
}
