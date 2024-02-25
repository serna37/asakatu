#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
vector<long long> mf;
long long modfact(int x) {
    if ((int)mf.size() > x) return mf[x];
    if (mf.empty()) mf.push_back(1);
    for (int i = mf.size(); i <= x; i++) mf.push_back(mf.back() * i % MOD);
    return mf[x];
}
int main() {
    int N;
    cin >> N;
    cout << modfact(N) << endl;
}
