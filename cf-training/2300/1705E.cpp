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
const int maxn = 2e5 + 35;
const int mx = 2e5 + 30;
const ll mod = 998244353;
int n, q;
int a[maxn], count[maxn];
struct node {
    int have[2];
    int pos[2];
    int lz;
}t[maxn << 2];
void push_dn(int rt, int l, int r) {
    if (t[rt].lz) {
        int mid = (l + r) / 2;
        for (int i = 0; i < 2; ++i) {
            t[rt << 1].have[i] = t[rt].have[i];
            t[rt << 1].pos[i] = l;
            t[rt << 1 | 1].have[i] = t[rt].have[i];
            t[rt << 1 | 1].pos[i] = mid + 1;
        }
        t[rt << 1].lz = 1;
        t[rt << 1 | 1].lz = 1;
        t[rt].lz = 0;
    } 
}
void push_up(int rt) {
    for (int i = 0; i < 2; ++i) {
        t[rt].have[i] = t[rt << 1].have[i] | t[rt << 1 | 1].have[i];
        if (t[rt << 1].have[i]) {
            t[rt].pos[i] = t[rt << 1].pos[i];
        } else {
            t[rt].pos[i] = t[rt << 1 | 1].pos[i];
        }
    }
}
void build(int rt, int l, int r) {
    t[rt].lz = 0;
    if (l == r) {
        t[rt].have[count[l]] = 1;
        t[rt].have[count[l] ^ 1] = 0;
        t[rt].pos[0] = t[rt].pos[1] = l;
        return;
    }
    int mid = (l + r) / 2;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    push_up(rt);
}
void update(int rt, int l, int r, int xl, int xr, int val) {
    if (xl == l && xr == r) {
        t[rt].lz = 1;
        t[rt].have[val] = 1;
        t[rt].have[val ^ 1] = 0;
        t[rt].pos[0] = t[rt].pos[1] = l; 
        return;
    }
    push_dn(rt, l, r);
    int mid = (l + r) / 2;
    if (xl <= mid) update(rt << 1, l, mid, xl, std::min(mid, xr), val);
    if (xr > mid) update(rt << 1 | 1, mid + 1, r, std::max(mid + 1, xl), xr, val);
    push_up(rt);
}
int get_nearest(int rt, int l, int r, int xl, int xr, int val) {
    if (xl == l && xr == r) {
        return t[rt].have[val] ? t[rt].pos[val] : mx + 1;
    }
    push_dn(rt, l, r);
    int mid = (l + r) / 2;
    int res = mx + 1;
    if (xl <= mid) res = get_nearest(rt << 1, l, mid, xl, std::min(mid, xr), val);
    if (xr > mid) res = std::min(res, get_nearest(rt << 1 | 1, mid + 1, r, std::max(mid + 1, xl), xr, val));
    return res;
}
int mx_one(int rt, int l, int r) {
    if (l == r) {
        return l;
    }
    push_dn(rt, l, r);
    int mid = (l + r) / 2;
    if (t[rt << 1 | 1].have[1]) return mx_one(rt << 1 | 1, mid + 1, r);
    else return mx_one(rt << 1, l, mid);
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    
    std::cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        ++count[a[i]];
    }
    for (int i = 1; i <= mx; ++i) {
        count[i + 1] += count[i] / 2;
        count[i] %= 2;
    }
    build(1, 1, mx);
    for (int i = 1; i <= q; ++i) {
        int k, l;
        std::cin >> k >> l;
        int pos = get_nearest(1, 1, mx, a[k], mx, 1);
        update(1, 1, mx, pos, pos, 0);
        if (a[k] < pos) update(1, 1, mx, a[k], pos - 1, 1);
        a[k] = l;
        pos = get_nearest(1, 1, mx, a[k], mx, 0);
        update(1, 1, mx, pos, pos, 1);
        if (a[k] < pos) update(1, 1, mx, a[k], pos - 1, 0);
        std::cout << mx_one(1, 1, mx) << '\n';
    }
    return 0;
}
// 15 : 26 - 16 : 15