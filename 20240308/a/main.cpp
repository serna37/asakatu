#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    auto test = [&](long long x) -> bool { return x * (x + 1) / 2 >= N; };
    long long L = 0, R = 1, MID = 0;
    while (!test(R)) R <<= 1; // 指数探索
    while (R - L > 1) (test(MID = L + (R - L) / 2) ? R : L) = MID;
    cout << R << endl;
}
