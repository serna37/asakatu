#include <bits/stdc++.h>
using namespace std;
int main() {
    int A, B;
    cin >> A >> B;
    set<int> st = {1, 2, 3};
    st.erase(A);
    st.erase(B);
    cout << *st.begin() << endl;
}
