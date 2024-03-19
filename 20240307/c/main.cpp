#include <bits/stdc++.h>
using namespace std;
int main() {
    long long A, B, C;
    cin >> A >> B >> C;
    int cnt = 0;
    if (B % 4 == 0) {
        cnt = 4;
    } else if (B % 4 == 1) {
        cnt = 1;
    } else if (B % 4 == 2) {
        cnt = (C == 1 ? 2 : 4);
    } else {
        cnt = (C % 2 == 0 ? 1 : 3);
    }
    // int a = to_string(A).back() - '0';
    // int b = to_string(B).back() - '0';
    // auto cal = [](int C, int b) -> int {
    // C %= 4;
    // int cnt = 0;
    // if (C == 0) {
    // if (b == 5) {
    // cnt = 5;
    //} else {
    // cnt = (b % 2 == 0 ? 6 : 1);
    //}
    //} else if (C == 1) {
    // cnt = b;
    //} else if (C == 2) {
    // if (b == 2 or b == 8) {
    // cnt = 4;
    //} else if (b == 4 or b == 6) {
    // cnt = 6;
    //} else if (b == 1 or b == 9) {
    // cnt = 1;
    //} else if (b == 3 or b == 7) {
    // cnt = 9;
    //} else {
    // cnt = 5;
    //}
    //} else if (C == 3) {
    // if (b == 2 or b == 3 or b == 7 or b == 8) {
    // cnt = 10 - b;
    //} else {
    // cnt = b;
    //}
    //}
    // return cnt;
    //};
    // int cnt = cal(C, b);
    long long ans = 1;
    for (int i = 0; i < cnt; i++) {
        ans *= A;
        ans %= 10;
    }
    // int ans = cal(cnt, a);
    cout << ans << endl;
}
