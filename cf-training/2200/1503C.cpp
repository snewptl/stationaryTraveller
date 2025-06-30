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
const int maxn = 2e5 + 5;
const ll mod = 998244353;
int n;
pii a[maxn];
ll ans;
std::vector<pii> vec;
struct node {
    ll val;
    ll lazy;
} t[maxn << 2];
void build(int rt, int l, int r) {
    int mid = l + r >> 1;
    if (l == r) {
        t[rt].lazy = (l == 0 ? -1e18 : 0);
        t[rt].val = (l == 0 ? 0 : 1e18);
        return;
    }
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
}
void push_dn(int rt) {
    t[rt << 1].lazy = std::min(t[rt].lazy, t[rt << 1].lazy);
    t[rt << 1 | 1].lazy = std::min(t[rt].lazy, t[rt << 1 | 1].lazy);
    t[rt].lazy = 0;
    t[rt << 1].val 
}
void update(int rt, int l, int r, int xl, int xr, ll val, ll lazy) {
    int mid = l + r >> 1;
    if (xl == l && xr == r) {
        t[rt].val = val;
        t[rt].lazy = lazy;
        return;
    }
    push_dn(rt);
    if (xl <= l) update(rt << 1, l, mid, xl, std::min(xr, mid), val, lazy);
    if (xr > mid) update(rt << 1 | 1, mid + 1, r, std::max(xl, mid + 1), xr, val, lazy);
}
node query(int rt, int l, int r, int xp) {
    int mid = l + r >> 1;
    if (l == r) {
        return t[rt];
    }
    push_dn(rt);
    if (xp <= mid) return query(rt << 1, l, mid, xp);
    else return query(rt << 1 | 1, mid + 1, r, xp);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    ans = 0;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i].first >> a[i].second;
        if (i != 1) vec.push_back(a[i]);
        ans += a[i].second;
    }
    std::sort(all(vec));
    if (vec[0].first > a[1].first || vec.back().first < a[1].first) vec.push_back(a[1]);
    std::sort(all(vec));
    n = vec.size();
    build(1, 0, n - 1);
    for (int i = 0; i < n - 1; ++i) {
        auto it = query(1, 0, n - 1, i);
        ll val = std::max(0ll, vec[i].first + it.lazy);
        update(1, 0, n - 1, 0, n - 1, it.val + val, -vec[i].second - vec[i].first);
    }
    std::cout << query(1, 0, n - 1, n - 1).val << '\n';
    return 0;
}

// 23 : 22 - 00 : 28