#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N;
    cin >> N;
    set<long long> st;
    for (long long i = 2; i * i <= N; i++) {
        long long a = i * i;
        while (a <= N) {
            st.insert(a);
            a *= i;
        }
    }
    cout << N - st.size() << endl;
}
