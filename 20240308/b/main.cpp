#include <bits/stdc++.h>
using namespace std;
/**
 * ランレングス圧縮
 */
template <typename STRING = string, typename CHAR = char>
vector<pair<CHAR, int>> run_length(STRING &S) {
    vector<pair<CHAR, int>> res;
    for (auto &&x : S) {
        if (res.empty() or res.back().first != x) {
            res.emplace_back(x, 0);
        }
        res.back().second++;
    }
    return res;
}
/**
 * Fenwick Tree
 */
template <typename Monoid> struct FwkTree {
    using M = Monoid;
    using T = typename M::value_type;

  private:
    int N;
    vector<T> node;
    T tot;
    void init() {
        node.assign(N + 1, M::e);
        tot = M::e;
    }
    void bind(T &x, const T &y) {
        x = M::op(x, y);
    }

  public:
    FwkTree(int n) : N(n) {
        init();
    }
    FwkTree(const vector<T> &a) : N(a.size()) {
        init();
        for (int i = 1; i <= N; i++) {
            bind(tot, a[i - 1]);
            bind(node[i], a[i - 1]);
            int f = i + (i & -i);
            if (f <= N) bind(node[f], node[i]);
        }
    }
    void act(int i, const T &x) {
        bind(tot, x);
        for (++i; i <= N; i += i & -i) bind(node[i], x);
    }
    T get(int r) {
        T ans = M::e;
        for (++r; r; r -= r & -r) bind(ans, node[r]);
        return ans;
    }
    T top() {
        return tot;
    }
};
/**
 * モノイド
 */
template <typename T> struct Madd {
    using value_type = T;
    static constexpr T e = 0;
    static constexpr T op(const T &x, const T &y) noexcept {
        return x + y;
    }
};
/**
 * 座標圧縮
 * @return 圧縮後、変換辞書
 */
template <typename T> pair<vector<T>, vector<T>> zip(vector<T> a) {
    vector<T> c = a;
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    for (auto &v : a) v = lower_bound(c.begin(), c.end(), v) - c.begin();
    return {a, c};
}
int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    auto rle = run_length(S);
    auto [ch, cnt] = rle.front();
    vector<int> A;
    // A.push_back(1);
    if (ch == '>') {
        A.push_back(cnt + 1);
    } else {
        A.push_back(1);
    }
    for (auto &&[ch, cnt] : rle) {
        int b = A.back();
        if (ch == '<') {
            for (int i = 0; i < cnt; i++) {
                A.push_back(++b);
            }
        } else {
            if (b - cnt < 1) {
                b += cnt - 1;
            }
            for (int i = 0; i < cnt; i++) {
                A.push_back(--b);
            }
        }
    }
    // int mi = *min_element(A.begin(), A.end());
    // if (mi < 1) {
    // for (int i = 0; i < N; i++) {
    // A[i] += abs(1 - mi);
    //}
    //}
    cout << "debug_A:";                // TODO debug
    for (auto v : A) cout << " " << v; // TODO debug
    cout << endl;                      // TODO debug
    auto cal = [&](vector<int> A) -> int {
        auto [comp, cvt] = zip(A);
        // Aの転頭数
        int inv = 0;
        FwkTree<Madd<int>> fwk(cvt.size());
        for (int i = 0; i < N; i++) {
            inv += fwk.top() - fwk.get(comp[i]);
            fwk.act(comp[i], 1);
        }
        return inv;
    };
    cout << cal(A) << endl;
}
