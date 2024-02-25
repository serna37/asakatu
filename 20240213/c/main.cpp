#include <bits/stdc++.h>
using namespace std;
int main() {
    int H, W, N;
    cin >> H >> W >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        A[i]--, B[i]--;
    }
    set<int> row, col;
    for (int i = 0; i < H; i++) {
        row.insert(A[i]);
    }
    for (int i = 0; i < W; i++) {
        col.insert(B[i]);
    }
    int R = row.size(), C = col.size();
    auto compress = []<class T>(vector<T> &a) -> int {
        vector<T> c = a;
        sort(c.begin(), c.end());
        c.erase(unique(c.begin(), c.end()), c.end());
        for (auto &v : a) v = lower_bound(c.begin(), c.end(), v) - c.begin();
        return c.size();
    };
    int r = compress(A), c = compress(B);
    vector<vector<int>> S(R, vector<int>(C, 0));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
        }
    }
}
