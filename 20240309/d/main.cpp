#include <bits/stdc++.h>
using namespace std;
template <class T> constexpr T inf = 0;
template <> constexpr int inf<int> = 1001001001;
template <> constexpr long long inf<long long> = 1001001001001001001ll;
int main() {
    int MAX = 15 * 1e5;
    set<int> st;
    for (int i = 0; i <= MAX; i++) {
        st.insert(i);
    }
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    multiset<int> red;
    for (int i = 0; i < M; i++) {
        st.erase(A[i]);
        red.insert(A[i]);
    }
    int ans = inf<int>;
    for (int i = 0; i < N - M + 1; i++) {
        ans = min(ans, *st.begin());
        red.erase(red.find(A[i]));
        red.insert(A[i + M]);
        st.erase(A[i + M]);
        if (!red.count(A[i])) {
            st.insert(A[i]);
        }
    }
    cout << ans << endl;
}
