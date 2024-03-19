#include <bits/stdc++.h>
using namespace std;
int main() {
    int MAX = 2e3;
    set<int> st;
    for (int i = 0; i <= MAX; i++) {
        st.insert(i);
    }
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        st.erase(A[i]);
    }
    cout << *st.begin() << endl;
}
