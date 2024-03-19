#include <bits/stdc++.h>
using namespace std;
template <class T> constexpr T inf = 0;
template <> constexpr int inf<int> = 1001001001;
template <> constexpr long long inf<long long> = 1001001001001001001ll;
template <typename MonoidAct> struct LazySegTree {
    using M = typename MonoidAct::M_m;
    using A = typename MonoidAct::M_a;
    using T = typename M::value_type;
    using U = typename A::value_type;

  private:
    int N, log, size;
    vector<T> node;
    vector<U> lazy;
    void init() {
        log = 1;
        while ((1 << log) < N) ++log;
        size = 1 << log;
        node.assign(size << 1, M::e);
        lazy.assign(size, A::e);
    }
    void update(int i) {
        node[i] = M::op(node[i << 1 | 0], node[i << 1 | 1]);
    }
    void apply_at(int k, U a) {
        int topbit = k == 0 ? -1 : 31 - __builtin_clz(k);
        long long sz = 1 << (log - topbit);
        node[k] = MonoidAct::act(node[k], a, sz);
        if (k < size) lazy[k] = A::op(lazy[k], a);
    }
    void propagate(int k) {
        if (lazy[k] == A::e) return;
        apply_at((k << 1 | 0), lazy[k]);
        apply_at((k << 1 | 1), lazy[k]);
        lazy[k] = A::e;
    }

  public:
    LazySegTree(int n) : N(n) {
        init();
    }
    LazySegTree(const vector<T> &a) : N(a.size()) {
        init();
        for (int i = 0; i < N; ++i) node[i + size] = a[i];
        for (int i = size - 1; i >= 1; --i) update(i);
    }
    T operator[](int p) {
        p += size;
        for (int i = log; i >= 1; --i) propagate(p >> i);
        return node[p];
    }
    vector<T> getall() {
        for (int i = 1; i < size; i++) propagate(i);
        return {node.begin() + size, node.begin() + size + N};
    }
    void set(int p, const T &x) {
        p += size;
        for (int i = log; i >= 1; --i) propagate(p >> i);
        node[p] = x;
        for (int i = 1; i <= log; ++i) update(p >> i);
    }
    void act(int p, const T &x) {
        p += size;
        for (int i = log; i >= 1; --i) propagate(p >> i);
        node[p] = M::op(node[p], x);
        for (int i = 1; i <= log; ++i) update(p >> i);
    }
    T get(int l, int r) {
        if (l == r) return M::e;
        l += size, r += size;
        for (int i = log; i >= 1; --i) {
            if (((l >> i) << i) != l) propagate(l >> i);
            if (((r >> i) << i) != r) propagate((r - 1) >> i);
        }
        T L = M::e, R = M::e;
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) L = M::op(L, node[l++]);
            if (r & 1) R = M::op(node[--r], R);
        }
        return M::op(L, R);
    }
    T top() {
        return node[1];
    }
    void apply(int l, int r, U a) {
        if (l == r) return;
        l += size, r += size;
        for (int i = log; i >= 1; --i) {
            if (((l >> i) << i) != l) propagate(l >> i);
            if (((r >> i) << i) != r) propagate((r - 1) >> i);
        }
        int l2 = l, r2 = r;
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) apply_at(l++, a);
            if (r & 1) apply_at(--r, a);
        }
        l = l2, r = r2;
        for (int i = 1; i <= log; ++i) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }
    template <typename F> int max_right(const F &test, int L) {
        if (L == N) return N;
        L += size;
        for (int i = log; i >= 1; --i) propagate(L >> i);
        T sm = M::e;
        do {
            while (L % 2 == 0) L >>= 1;
            if (!test(M::op(sm, node[L]))) {
                while (L < size) {
                    propagate(L);
                    L = 2 * L;
                    if (test(M::op(sm, node[L]))) sm = M::op(sm, node[L++]);
                }
                return L - size;
            }
            sm = M::op(sm, node[L++]);
        } while ((L & -L) != L);
        return N;
    }
    template <typename F> int min_left(const F test, int R) {
        if (R == 0) return 0;
        R += size;
        for (int i = log; i >= 1; i--) propagate((R - 1) >> i);
        T sm = M::e;
        do {
            R--;
            while (R > 1 && (R % 2)) R >>= 1;
            if (!test(M::op(node[R], sm))) {
                while (R < size) {
                    propagate(R);
                    R = 2 * R + 1;
                    if (test(M::op(node[R], sm))) sm = M::op(node[R--], sm);
                }
                return R + 1 - size;
            }
            sm = M::op(node[R], sm);
        } while ((R & -R) != R);
        return 0;
    }
};
template <typename T> struct Mmin {
    using value_type = T;
    static constexpr T e = inf<T>;
    static constexpr T op(const T &x, const T &y) noexcept {
        return min(x, y);
    }
};
template <typename T> struct Madd {
    using value_type = T;
    static constexpr T e = 0;
    static constexpr T op(const T &x, const T &y) noexcept {
        return min(x, y);
    }
};
template <typename T> struct MAminadd {
    using M_m = Mmin<T>;
    using M_a = Madd<T>;
    using M = typename M_m::value_type;
    using A = typename M_a::value_type;
    static constexpr M act(const M &m, const A &a, const long long &size) {
        (void)size; // unused
        // return m == inf<T> ? m : m + a;
        return min(m, a);
    }
};
int main() {
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;
    // LazySegTree<MAminadd<int>> dp(N + 1);
    vector<int> dp(N + 1, inf<int>);
    // dp.set(0, 0);
    dp[0] = 0;
    for (int i = 0; i <= N; i++) {
        if (S[i] == '1') continue;
        // dp.apply(i + 1, min(i + 1 + M, N), dp[i] + 1);
        for (int j = 1; j <= M; j++) {
            dp[min(i + j, N)] = min(dp[min(i + j, N)], dp[i] + 1);
        }
    }
    if (dp[N] == inf<int>) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> ans;
    ans.push_back(N);
    int c = dp[N] - 1;
    while (c) {
        int f = lower_bound(dp.begin(), dp.end(), c) - dp.begin();
        ans.push_back(f);
        c--;
    }
    ans.push_back(0);
    int n = ans.size();
    reverse(ans.begin(), ans.end());
    vector<int> D(n - 1);
    for (int i = 0; i < n - 1; i++) {
        D[i] = ans[i + 1] - ans[i];
    }
    for (int i = 0; i < n - 1; i++) {
        if (i) cout << " ";
        cout << D[i];
    }
    cout << endl;
}
