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
int n;
pii seg[maxn];
int t[maxn << 2], lz[maxn << 2];
ll power[4][maxn];
void push_up(int rt) {
    t[rt] = std::max(t[rt << 1], t[rt << 1 | 1]);
}
void push_dn(int rt) {
    if (lz[rt]) {
        t[rt << 1] = lz[rt];
        t[rt << 1 | 1] = lz[rt];
        lz[rt << 1] = lz[rt];
        lz[rt << 1 | 1] = lz[rt];
        lz[rt] = 0;
    }
}
void update(int rt, int l, int r, int xl, int xr, int val) {
    if (l == xl && r == xr) {
        t[rt] = val;
        lz[rt] = val;
        return;
    }
    push_dn(rt);
    int mid = (l + r) / 2;
    if (xl <= mid) update(rt << 1, l, mid, xl, std::min(mid, xr), val);
    if (xr > mid) update(rt << 1 | 1, mid + 1, r, std::max(mid + 1, xl), xr, val);
    push_up(rt);
}
int query(int rt, int l, int r, int pos) {
    if (l == r) {
        return t[rt];
    }
    push_dn(rt);
    int mid = (l + r) / 2;
    if (pos <= mid) return query(rt << 1, l, mid, pos);
    else return query(rt << 1 | 1, mid + 1, r, pos);
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> seg[i].first >> seg[i].second;
        update(1, 0, 3e5, seg[i].first, seg[i].second, i);
    }
    for (int i = 2; i <= 3; ++i) {
        power[i][0] = 1;
        for (int j = 1; j <= n; ++j) {
            power[i][j] = power[i][j - 1] * i % mod;
        }
    }

    ll ans = 0;
    for (int i = 0; i <= 3e5; ++i) {
        int div = query(1, 0, 3e5, i);
        if (!div) continue;
        if (div == 1) {
            ans += power[3][div - 1] * power[2][n - div];
        } else {
            ans += power[3][div - 2] * power[2][n - div + 1];
        }
        
        ans %= mod;
    }
    std::cout << ans << '\n';


    return 0;
}
// 23 : 41 -  00 : 12