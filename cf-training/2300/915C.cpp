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
const int maxn = 3e5 + 5;
const ll mod = 998244353;
struct tree {
    pii seg;
    int len;
    int count;
    int lson, rson;
    int lazy;
    void update_seg(int l, int r) {
        seg = {l, r};
        len = r - l + 1;
    }
}t[maxn << 2];
int q, n;
int count;
void push_dn(int rt) {
    tree &l = t[t[rt].lson], &r = t[t[rt].rson], &p = t[rt];
    if (p.lazy) {
        l.lazy = r.lazy = p.lazy;
        if (p.lazy == 1) {
            l.count = r.count = 0;
        } else {
            l.count = l.len;
            r.count = r.len;
        }
        p.lazy = 0;
    }
}
void push_up(int rt) {
    tree &l = t[t[rt].lson], &r = t[t[rt].rson], &p = t[rt];
    p.count = l.count + r.count;
}
void update(int rt, int xl, int xr, int k) {
    auto [l, r] = t[rt].seg;
    int mid = (l + r) / 2;
    if (xl == l && xr == r) {
        t[rt].lazy = k;
        if (k == 1) t[rt].count = 0;
        else t[rt].count = r - l + 1;
        return;
    }
    if (!t[rt].lson) {
        t[rt].lson = ++count;
        t[rt].rson = ++count;
        tree &lnode = t[t[rt].lson], &rnode = t[t[rt].rson], &pndoe = t[rt];
        if (xr == r) {
            lnode.update_seg(l, xl - 1);
            rnode.update_seg(xl, r);
        } else {
            lnode.update_seg(l, xr);
            rnode.update_seg(xr + 1, r);
        }
    }
    tree &lnode = t[t[rt].lson], &rnode = t[t[rt].rson], &pndoe = t[rt];
    push_dn(rt);
    if (xl <= lnode.seg.second) {
        update(t[rt].lson, xl, std::min(lnode.seg.second, xr), k);
    }
    if (xr >= rnode.seg.first) {
        update(t[rt].rson, std::max(rnode.seg.first, xl), xr, k);
    }
    push_up(rt);
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> q;
    ++count;
    t[1].update_seg(1, n);
    t[1].count = n;
    t[1].lazy = 2;
    for (int i = 1; i <= q; ++i) {
        int l, r, k;
        std::cin >> l >> r >> k;
        update(1, l, r, k);
        std::cout << t[1].count << '\n';
    }
    return 0;
}
// 16 : 49 - 