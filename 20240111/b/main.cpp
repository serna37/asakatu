#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    vector<string> p(a), q(b);
    vector<vector<string>> x = {
        {"7", "8", "9", "0"},
        {"4", "5", "6"},
        {"2", "3"},
        {"1"},
    };
    for (int i = 0; i < a; i++) {
        cin >> p[i];
        for (int ii = 0; ii < 4; ii++) {
            auto xx = x[ii];
            int siz = xx.size();
            for (int iii = 0; iii < siz; iii++) {
                if (xx[iii] == p[i]) {
                    x[ii][iii] = ".";
                }
            }
        }
    }
    for (int i = 0; i < b; i++) {
        cin >> q[i];
        for (int ii = 0; ii < 4; ii++) {
            auto xx = x[ii];
            int siz = xx.size();
            for (int iii = 0; iii < siz; iii++) {
                if (xx[iii] == q[i]) {
                    x[ii][iii] = "o";
                }
            }
        }
    }
    for (int ii = 0; ii < 4; ii++) {
        auto xx = x[ii];
        int siz = xx.size();
        for (int iii = 0; iii < siz; iii++) {
            if (xx[iii] != "." && xx[iii] != "o") {
                x[ii][iii] = "x";
            }
        }
    }
    string sp = "";
    for (int ii = 0; ii < 4; ii++) {
        auto xx = x[ii];
        int siz = xx.size();
        for (int iii = 0; iii < siz; iii++) {
            if (iii) {
                cout << " ";
            } else {
                cout << sp;
            }
            cout << xx[iii];
        }
        cout << endl;
        sp += " ";
    }
    cout << endl;
}
