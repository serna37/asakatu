#include <bits/stdc++.h>
using namespace std;
double PI = acos(-1);
int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> X(N), R(N), H(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> R[i] >> H[i];
    }
    for (int i = 0; i < Q; i++) {
        int A, B;
        cin >> A >> B;
        long double ans = 0;
        for (int i = 0; i < N; i++) {
            long double tmp = 0;
            long long h = X[i] + H[i];
            if (A <= X[i] and X[i] <= B and A <= h and h <= B) {
                tmp = H[i] * R[i] * R[i] * PI / 3;
            }
            if (X[i] < A and A <= h and h <= B) {
                long long r = (h - A) * R[i] / H[i];
                tmp = (h - A) * r * r * PI / 3;
            }
            if (B < h and A <= X[i] and X[i] <= B) {
                long long r = (h - B) * R[i] / H[i];
                tmp =
                    (H[i] * R[i] * R[i] * PI / 3) - ((h - B) * r * r * PI / 3);
            }
            if (X[i] < A and B < h) {
                long long ra = (h - A) * R[i] / H[i];
                long long rb = (h - B) * R[i] / H[i];
                tmp =
                    ((h - A) * ra * ra * PI / 3) - ((h - B) * rb * rb * PI / 3);
            }
            ans += tmp;
        }
        cout << ans << endl;
    }
}
