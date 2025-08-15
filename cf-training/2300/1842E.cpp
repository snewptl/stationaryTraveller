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
int n, k;
ll A;
std::vector<std::vector<pii>> line; 
ll sum;
ll dp[maxn];
namespace T {
    ll t[maxn << 2], lz[maxn << 2];
    void push_dn(int rt) {
        t[rt << 1] += lz[rt];
        t[rt << 1 | 1] += lz[rt];
        lz[rt << 1] += lz[rt];
        lz[rt << 1 | 1] += lz[rt];
        lz[rt] = 0;
    }
    void build(int rt, int l, int r) {
        if (l == r) {
            t[rt] = -1e18;
            return;
        }
        t[rt] = -1e18;
        int mid = (l + r) / 2;
        build(rt << 1, l, mid);
        build(rt << 1 | 1, mid + 1, r);
    }
    void update(int rt, int l, int r, int xl, int xr, ll delta) {
        if (xl == l && xr == r) {
            t[rt] += delta;
            lz[rt] += delta;
            return;
        }
        int mid = (l + r) / 2;
        push_dn(rt);
        if (xl <= mid) update(rt << 1, l, mid, xl, std::min(mid, xr), delta);
        if (xr > mid) update(rt << 1 | 1, mid + 1, r, std::max(xl, mid + 1), xr, delta);
        t[rt] = std::max(t[rt << 1], t[rt << 1 | 1]);
    }
    ll query(int rt, int l, int r, int xl, int xr) {
        if (xl == l && xr == r) {
            return t[rt];
        }
        int mid = (l + r) / 2;
        push_dn(rt);
        ll res = -1e18;
        if (xl <= mid) res = query(rt << 1, l, mid, xl, std::min(xr, mid));
        if (xr > mid) res = std::max(res, query(rt << 1 | 1, mid + 1, r, std::max(xl, mid + 1), xr));
        return res;
    }
    void set(int rt, int l, int r, int pos, ll x) {
        if (l == r) {
            t[rt] = x;
            return;
        }
        push_dn(rt);
        int mid = (l + r) / 2;
        if (pos <= mid) set(rt << 1, l, mid, pos, x);
        if (pos > mid) set(rt << 1 | 1, mid + 1, r, pos, x);
        t[rt] = std::max(t[rt << 1], t[rt << 1 | 1]);
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
        std::cin >> n >> k >> A;
        line.resize(k + 1);
        for (int i = 1; i <= n; ++i) {
            int x, y, w;
            std::cin >> x >> y >> w;
            line[k - y].push_back({x, w});
            sum += w;
        }
        dp[0] = 0;
        T::build(1, 0, k - 1);
        T::set(1, 0, k - 1, 0, dp[0]);
        for (int i = 1; i <= k; ++i) {
            dp[i] = dp[i - 1];
            T::update(1, 0, k - 1, 0, i - 1, -A);
            for (auto [x, w] : line[i]) {
                T::update(1, 0, k - 1, 0, x, w);
            }
            dp[i] = std::max(dp[i], T::query(1, 0, k - 1, 0, i - 1));
            T::set(1, 0, k - 1, i, dp[i]);
        }
        std::cout << sum - dp[k] << '\n';
    }

    return 0;
}
// 19 : 35 - 