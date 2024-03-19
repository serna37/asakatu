#include <bits/stdc++.h>
using namespace std;
template <class T> constexpr T inf = 0;
template <> constexpr int inf<int> = 1001001001;
template <> constexpr long long inf<long long> = 1001001001001001001ll;
template <typename T> map<T, int> p_fact(T N) {
    map<T, int> P;
    for (T i = 2; i * i <= N; i++) {
        while (N % i == 0) {
            P[i]++;
            N /= i;
        }
    }
    if (N > 1) P[N]++;
    return P;
}
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int G = 0;
    for (int i = 0; i < N; i++) {
        G = gcd(A[i], G);
    }
    vector<int> D(N);
    for (int i = 0; i < N; i++) {
        D[i] = A[i] / G;
    }
    vector<map<int, int>> B(N);
    int mi2 = inf<int>, mi3 = inf<int>;
    for (int i = 0; i < N; i++) {
        B[i] = p_fact(D[i]);
        if (!B[i].count(2)) {
            B[i][2] = 0;
        }
        if (!B[i].count(3)) {
            B[i][3] = 0;
        }
        for (auto [num, cnt] : B[i]) {
            if (num != 2 and num != 3) {
                cout << -1 << endl;
                return 0;
            }
            if (num == 2) {
                mi2 = min(mi2, cnt);
            }
            if (num == 3) {
                mi3 = min(mi3, cnt);
            }
        }
    }
    if (G == 1) {
        mi2 = 0, mi3 = 0;
    }
    long long c2 = 0, c3 = 0;
    for (int i = 0; i < N; i++) {
        for (auto [num, cnt] : B[i]) {
            if (num == 2) {
                c2 += cnt - mi2;
            }
            if (num == 3) {
                c3 += cnt - mi3;
            }
        }
    }
    cout << c2 + c3 << endl;
}
