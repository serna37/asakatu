#include <bits/stdc++.h>
using namespace std;
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
    vector<int> h(N);
    for (auto &&v : h) {
        cin >> v;
    }
    auto [comp, cvt] = zip(h);
    int s = comp.size();
    FwkTree<Madd<int>> fwk(s);
    vector<int> ans(N);
    for (int i = 0; i < N; i++) {
        ans += fwk.top() - fwk.get(comp[i]);
        fwk.act(comp[i], 1);
    }
    for (int i = 0; i < N; i++) {
        inv += fwk.top() - fwk.get(comp[i]);
        fwk.act(comp[i], 1);
    }
}
