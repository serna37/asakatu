#include <bits/stdc++.h>
using namespace std;
int main() {
    string S1, S2, S3, S4;
    cin >> S1 >> S2 >> S3 >> S4;
    vector<string> a = {"H", "2B", "3B", "HR"};
    bool allma = true;
    for (string v : a) {
        allma &= S1 == v or S2 == v or S3 == v or S4 == v;
    }
    cout << (allma ? "Yes" : "No") << endl;
}
