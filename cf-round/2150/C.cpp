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
const int maxn = 2e5 + 5;
const ll mod = 998244353;
int n, a[maxn], b[maxn];
ll v[maxn];
int rank_b[maxn];
struct node {
    int flag;
    ll max, lazy;
}t[maxn << 2];
void push_up(int rt) {
    t[rt].flag = t[rt << 1].flag | t[rt << 1 | 1].flag;
    if (t[rt].flag) {
        if (t[rt << 1].flag) {
            if (t[rt << 1 | 1].flag) {
                t[rt].max = std::max(t[rt << 1].max, t[rt << 1 | 1].max);
            } else {
                t[rt].max = t[rt << 1].max;
            }
        } else {
            t[rt].max = t[rt << 1 | 1].max;
        }
    }
}
void push_dn(int rt) {
    if (t[rt].lazy) {
        t[rt << 1].lazy += t[rt].lazy;
        t[rt << 1].max += t[rt].lazy;
        t[rt << 1 | 1].lazy += t[rt].lazy;
        t[rt << 1 | 1].max += t[rt].lazy; 
        t[rt].lazy = 0;
    }
}
void build(int rt, int l, int r) {
    int mid = (l + r) / 2;
    t[rt].max = 0;
    t[rt].lazy = 0;
    if (l == r) {
        t[rt].flag = 0;
        if (l == 0) t[rt].flag = 1;
        return;
    }
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    push_up(rt);
}
void update(int rt, int l, int r, int xl, int xr, ll add) {
    if (l == xl && r == xr) {
        t[rt].lazy += add;
        t[rt].max += add;
        return;
    }
    int mid = (l + r) / 2;
    push_dn(rt);
    if (xl <= mid) update(rt << 1, l, mid, xl, std::min(xr, mid), add);
    if (xr > mid) update(rt << 1 | 1, mid + 1, r, std::max(xl, mid + 1), xr, add);
    push_up(rt);
}
void modify(int rt, int l, int r, int xp, ll val) {
    if (l == r) {
        t[rt].max = val;
        t[rt].flag = 1;
        return;
    }
    int mid = (l + r) / 2;
    push_dn(rt);
    if (xp <= mid) modify(rt << 1, l, mid, xp, val);
    else modify(rt << 1 | 1, mid + 1, r, xp, val);
    push_up(rt);
}
ll query(int rt, int l, int r, int xl, int xr) {
    if (xl == l && xr == r) {
        return t[rt].max;
    }
    int mid = (l + r) / 2;
    push_dn(rt);
    ll res = -1e18;
    if (xl <= mid && t[rt << 1].flag) res = std::max(res, query(rt << 1, l, mid, xl, std::min(xr, mid)));
    if (xr > mid && t[rt << 1 | 1].flag) res = std::max(res, query(rt << 1 | 1, mid + 1, r, std::max(xl, mid + 1), xr));
    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            std::cin >> v[i];
        }
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            std::cin >> b[i];
            rank_b[b[i]] = i;

        }
        ll ans = 0;
        build(1, 0, n);
        for (int i = 1; i <= n; ++i) {
            ll val = v[a[i]];
            int pos = rank_b[a[i]];
            ll res = query(1, 0, n, 0, pos - 1);
            modify(1, 0, n, pos, res);
            update(1, 0, n, 0, pos - 1, val);
            ans = std::max(ans, t[1].max);
        }
        std::cout << ans << '\n';
    }

    return 0;
}
