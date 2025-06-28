#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <assert.h>
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
const ll mask = (1ull << 63) - 1;
int n, q;
ll a[maxn];
struct node {
    ll real, fake, lazy;
}t[maxn << 2];
void push_dn(int rt, int l, int r) {
    int mid = (l + r) >> 1;
    if (t[rt].lazy != mask) {
        t[rt << 1].lazy &= t[rt].lazy;
        t[rt << 1].real &= t[rt].lazy;
        if (mid - l + 1 > 1) t[rt << 1].fake &= t[rt].lazy;
        t[rt << 1 | 1].lazy &= t[rt].lazy;
        t[rt << 1 | 1].real &= t[rt].lazy;
        if (r - mid > 1) t[rt << 1 | 1].fake &= t[rt].lazy;
        t[rt].lazy = mask;
    }
}
void push_up(int rt) {
    t[rt].real = t[rt << 1].real & t[rt << 1 | 1].real;
    t[rt].fake = (t[rt << 1].real & t[rt << 1 | 1].fake) | (t[rt << 1 | 1].real & t[rt << 1].fake);
}
void build(int rt, int l, int r) {
    int mid = l + r >> 1;
    if (r == l) {
        t[rt].fake = mask;
        t[rt].real = a[l];
        t[rt].lazy = mask;
        return;
    } 
    t[rt].lazy = mask;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    push_up(rt);
}
void seq_update(int rt, int l, int r, int xl, int xr, ll val) {
    int mid = l + r >> 1;
    if (xl == l && xr == r) {
        t[rt].real &= val;
        if (r - l + 1 > 1) {
            t[rt].lazy &= val;
            t[rt].fake &= val;
        }
        return;
    }
    push_dn(rt, l, r);
    if (xl <= mid) seq_update(rt << 1, l, mid, xl, std::min(xr, mid), val);
    if (xr > mid) seq_update(rt << 1 | 1, mid + 1, r, std::max(xl, mid + 1), xr, val);
    push_up(rt);
}
void single_update(int rt, int l, int r, int s, ll val) {
    int mid = l + r >> 1;
    if (l == r) {
        t[rt].real = val;
        t[rt].fake = mask;
        return;
    }
    push_dn(rt, l, r);
    if (s <= mid) single_update(rt << 1, l, mid, s, val);
    else single_update(rt << 1 | 1, mid + 1, r, s, val);
    push_up(rt);    
}
pll query(int rt, int l, int r, int xl, int xr) {
    int mid = l + r >> 1;
    if (xl == l && xr == r) {
        return {t[rt].real, t[rt].fake};
    }
    push_dn(rt, l, r);
    pll res = {mask, mask};
    if (xl <= mid) {
        pll left = query(rt << 1, l, mid, xl, std::min(xr, mid));
        if (xr > mid) {
            pll right = query(rt << 1 | 1, mid + 1, r, std::max(xl, mid + 1), xr);
            ll new_fake = (left.first & right.second) | (right.first & left.second);
            ll new_real = left.first & right.first;
            return {new_real, new_fake};
        } else return left;
    } else {
        return query(rt << 1 | 1, mid + 1, r, std::max(xl, mid + 1), xr);
    }
}
int find_pos(int rt, int l, int r, int xl, int xr, ll val) {
    int mid = l + r >> 1;
    if (xl == l && xr == r && (t[rt].real & val)) return 0; 
    if (l == r) return l;
    push_dn(rt, l, r);
    if (xl <= mid) {
        int res = find_pos(rt << 1, l, mid, xl, std::min(xr, mid), val);
        if (res) return res;
    }
    return find_pos(rt << 1 | 1, mid + 1, r, std::max(xl, mid + 1), xr, val);
     
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
    }
    build(1, 1, n);
    for (int i = 1; i <= q; ++i) {
        ll opt, l, r, x, s;
        std::cin >> opt;
        if (opt == 1) {
            std::cin >> l >> r >> x;
            seq_update(1, 1, n, l, r, x);
        } else if (opt == 2) {
            std::cin >> s >> x;
            single_update(1, 1, n, s, x);
        } else {
            std::cin >> l >> r;
            pll res = query(1, 1, n, l, r);
            ll x = res.first ^ res.second;
            if (x == 0) std::cout << res.first << '\n';
            else {
                ll cur = 1;
                while (x > 1) cur *= 2, x /= 2;
                int pos = find_pos(1, 1, n, l, r, cur);
                ll ans = mask;
                if (pos > l) ans &= query(1, 1, n, l, pos - 1).first;
                if (pos < r) ans &= query(1, 1, n, pos + 1, r).first;
                std::cout << ans << '\n';
            }
        }
    }

    return 0;
}

// Ａ　Ｋ　Ｅ　Ｈ　M　F　B  J I G D L C