#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;
int main() {
    int Q;
    cin >> Q;
    const int N = Q;
    int atom = INF;
    vector<pair<int, int>> seg(Q << 1, {-1, atom});
    for (int i = 0; i < N; i++) {
        seg[i + N] = {i, atom};
    }
    int i = 0;
    bool verzin = true;
    bool sorted = false;
    vector<int> unorg;
    while (Q--) {
        int q;
        cin >> q;
        if (q == 1) {
            int x;
            cin >> x;
            unorg.push_back(x);
            sorted = false;
        } else if (q == 2) {
            if (verzin) {
                cout << unorg.front() << endl;
                unorg.erase(unorg.begin());
                continue;
            }
            if (sorted) {
                for (auto x : unorg) {
                    int t = i + N;
                    seg[t].second = x;
                    while (t >>= 1) {
                        if (seg[t << 1 | 0].second < seg[t << 1 | 1].second) {
                            seg[t] = seg[t << 1 | 0];
                        } else {
                            seg[t] = seg[t << 1 | 1];
                        }
                    }
                    i++;
                }
                unorg.clear();
            }
            pair<int, int> ans = {-1, INF};
            for (int l = N, r = N << 1; l < r; l >>= 1, r >>= 1) {
                if (l & 1) {
                    if (ans.second > seg[l].second) {
                        ans = seg[l];
                    }
                    l++;
                }
                if (r & 1) {
                    --r;
                    if (ans.second > seg[r].second) {
                        ans = seg[r];
                    }
                }
            }
            cout << ans.second << endl;
            int t = ans.first + N;
            seg[t].second = INF;
            while (t >>= 1) {
                if (seg[t << 1 | 0].second < seg[t << 1 | 1].second) {
                    seg[t] = seg[t << 1 | 0];
                } else {
                    seg[t] = seg[t << 1 | 1];
                }
            }
        } else {
            sorted = true;
            verzin = false;
        }
    }
}
