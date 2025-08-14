#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <assert.h>
#include <memory.h>
#include <cmath>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 1e6 + 5;
const ll mod = 998244353;
int n, q;
int a[maxn];
std::vector<std::vector<pii>> seg, ques;
std::vector<std::vector<int>> pos;
ll ans[maxn];
int suffix[maxn];
namespace Max {
    int t[maxn << 2];
    void push_up(int rt) {
        t[rt] = std::max(t[rt << 1], t[rt << 1 | 1]);
    }
    void build(int rt, int l, int r) {
        if (l == r) {
            t[rt] = 0;
            return;
        }
        int mid = (l + r) / 2;
        build(rt << 1, l, mid);
        build(rt << 1 | 1, mid + 1, r);
        push_up(rt);
    }
    void update(int rt, int l, int r, int pos, int x) {
        if (l == r) {
            t[rt] = x;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) update(rt << 1, l, mid, pos, x);
        else update(rt << 1 | 1, mid + 1, r, pos, x);
        push_up(rt);
    }
    int query(int rt, int l, int r, int xl, int xr) {
        if (xl == l && xr == r) {
            return t[rt];
        }
        int mid = (l + r) / 2;
        int res = 0;
        if (xl <= mid) res = query(rt << 1, l, mid, xl, std::min(xr, mid));
        if (xr > mid) res = std::max(res, query(rt << 1 | 1, mid + 1, r, std::max(mid + 1, xl), xr));
        return res;
    }
}
namespace T {
    int t[maxn << 2], lazy[maxn << 2];
    void push_dn(int rt) {
        if (lazy[rt]) {
            lazy[rt << 1] += lazy[rt];
            lazy[rt << 1 | 1] += lazy[rt];
            t[rt << 1] += lazy[rt];
            t[rt << 1 | 1] += lazy[rt];
            lazy[rt] = 0;
        }
    }
    void build(int rt, int l, int r) {
        lazy[rt] = 0;
        t[rt] = 0;
        if (l == r) {
            return;
        }
        int mid = (l + r) / 2;
        build(rt << 1, l, mid);
        build(rt << 1 | 1, mid + 1, r);
    }
    void update(int rt, int l, int r, int xl, int xr, int delta) {
        if (xl == l && xr == r) {
            t[rt] += delta;
            lazy[rt] += delta;
            return;
        }
        int mid = (l + r) / 2;
        push_dn(rt);
        if (xl <= mid) update(rt << 1, l, mid, xl, std::min(xr, mid), delta);
        if (xr > mid) update(rt << 1 | 1, mid + 1, r, std::max(mid + 1, xl), xr, delta);
    }
    int query(int rt, int l, int r, int xl, int xr) {
        if (xl == l && xr == r) {
            return t[rt];
        }
        int mid = (l + r) / 2;
        push_dn(rt);
        int res = 0;
        if (xl <= mid) res += query(rt << 1, l, mid, xl, std::min(xr, mid));
        if (xr > mid) res += query(rt << 1 | 1, mid + 1, r, std::max(mid + 1, xl), xr);
        return res;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    // std::cin >> T;
    while (T--) {
        std::cin >> n >> q;
        pos.resize(n + 1);
        seg.resize(n + 1);
        ques.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            if (!pos[a[i]].empty()) {
                seg[a[i]].push_back({pos[a[i]].back(), i});
            }
            pos[a[i]].push_back(i);
            suffix[a[i]] = 1;
        }
        for (int i = n; i >= 1; --i) {
            suffix[i] += suffix[i + 1];
        }
        for (int i = 1; i <= q; ++i) {
            int l, r;
            std::cin >> l >> r;
            ques[r].push_back({l, i});
        }
        Max::build(1, 1, n);
        T::build(1, 1, n);
        for (int r = 1; r <= n; ++r) {
            for (auto [pos_l, pos_r] : seg[r]) {
                ++pos_l;
                --pos_r;
                if(pos_l > pos_r) continue;
                int max = Max::query(1, 1, n, pos_l, pos_r);
                if (max) T::update(1, 1, n, 1, max, 1); 
            } 
            for (auto it : pos[r]) {
                Max::update(1, 1, n, it, r);
            }
            for (auto [l, id] : ques[r]) {
                ans[id] = suffix[l] - suffix[r + 1];
                if (l < r) ans[id] += T::query(1, 1, n, l, l);
                // int res = T::query(1, 1, n, l, l);
                // std::cout << res << '\n';
            }
        }
        for (int i = 1; i <= q; ++i) {
            std::cout << ans[i] << '\n';
        }

    }

    return 0;
}
/*
8
1
1
3
5
3
1
0
*/
