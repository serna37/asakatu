#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    int h = N / 3600;
    int m = N % 3600 / 60;
    int s = N % 60;
    string hh = to_string(h);
    if (hh.size() == 1) {
        hh = "0" + hh;
    }
    string mm = to_string(m);
    if (mm.size() == 1) {
        mm = "0" + mm;
    }
    string ss = to_string(s);
    if (ss.size() == 1) {
        ss = "0" + ss;
    }
    cout << hh << ":" << mm << ":" << ss << endl;
}
