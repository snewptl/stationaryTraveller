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
const int maxn =5e5 + 5;
const ll mod = 1e9 + 7;
int n;
ll a[maxn];
struct Tree {
    ll sum[2];
    ll count;
}t[maxn << 2];
void push_up(int rt) {
    for (int i = 0; i < 2; ++i) {
        t[rt].sum[i] = t[rt << 1].sum[i] + t[rt << 1 | 1].sum[i];
        t[rt].sum[i] %= mod;
    }
    t[rt].count = t[rt << 1].count + t[rt << 1 | 1].count;
}
pll merge(pll x, pll y) {
    return {x.first + y.first, x.second + y.second};
}
void build(int rt, int l, int r) {
    if (l == r) {
        t[rt].count = 1;
        t[rt].sum[0] = l;
        t[rt].sum[1] = n - l + 1;
        return;
    }
    int mid = (l + r) / 2;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    push_up(rt);
}
void update(int rt, int l, int r, int pos) {
    if (l == r) {
        t[rt].sum[0] = t[rt].sum[1] = 0;
        t[rt].count = 0;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) update(rt << 1, l, mid, pos);
    else update(rt << 1 | 1, mid + 1, r, pos);
    push_up(rt);
}
pll query(int rt, int l, int r, int xl, int xr, int sgn) {
    if (xl == l && xr == r) {
        return {t[rt].sum[sgn], t[rt].count};
    }
    int mid = (l + r) / 2;
    pll res = {0, 0};
    if (xl <= mid) res = query(rt << 1, l, mid, xl, std::min(xr, mid), sgn);
    if (xr > mid) res = merge(res, query(rt << 1 | 1, mid + 1, r, std::max(mid + 1, xl), xr, sgn));
    return res;
}
ll C(ll x, ll y = 2) {
    if (x < 2) return 0;
    return x * (x - 1) / 2;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    std::vector<pll> vec;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        vec.push_back({a[i], i});
    }
    build(1, 1, n);
    std::sort(all(vec));
    std::reverse(all(vec));
    ll ans = 0;
    for (auto [val, pos] : vec) {
        if (pos > 1) {
            pll res = query(1, 1, n, 1, pos - 1, 0);
            ans += res.first * (n - pos + 1) % mod * val % mod;
            ans %= mod;
        }
        if (pos < n) {
            pll res = query(1, 1, n, pos + 1, n, 1);
            ans += res.first * pos % mod * val % mod;
            ans %= mod;
        }
        ans += (C(n, 2) - C(pos - 1, 2) - C(n - pos, 2) + 1) % mod * val % mod;
        ans %= mod; 
        update(1, 1, n, pos);
    }
    std::cout << ans << '\n';

    return 0;
}
// 21 : 10 - 