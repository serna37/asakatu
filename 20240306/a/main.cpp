#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= 50000; i++) {
        int a = i * 1.08;
        if (a == N) {
            cout << i << endl;
            return 0;
        }
    }
    cout << ":(" << endl;
}
