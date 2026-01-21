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
const int maxn = 5e3 + 5;
const ll mod = 998244353;
int n;
int a[maxn];
int vis[maxn];
int nxt[maxn];
ll fw[maxn][maxn];
int lowbit(int x) {
    return x & (-x);
}
void update(int lev, int pos, ll val) {
    while (pos <= n) {
        fw[lev][pos] += val;
        fw[lev][pos] %= mod;
        pos += lowbit(pos);
    }
}
ll query(int lev, int pos) {
    ll res =  0;
    while (pos > 0) {
        res += fw[lev][pos];
        res %= mod;
        pos -= lowbit(pos);
    }
    return res;
}
ll quick_pow(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y & 1) {
            res *= x, res %= mod;
        }
        x *= x, x %= mod;
        y /= 2;
    }
    return res;
}
ll inv(ll x) {
    return quick_pow(x, mod - 2);
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    // std::cin >> n;
    // for (int i = 1; i <= n; ++i) {
    //     std::cin >> a[i];
    //     vis[a[i]] += 1;
    // }
    n = 5000;
    for (int i = 1; i <= n; ++i) {
        vis[i] = 1;
    }
    for (int i = n; i >= 1; --i) {
        nxt[i] = vis[i];
        if (i != n) nxt[i] += nxt[i + 1];
    }
    update(1, 1, inv(n));
    ll ans = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (!vis[j]) continue;
            ll base = vis[j] * query(i, j) % mod * inv(n - i) % mod;
            update(i + 1, j + 1, base);
            ans +=  base * (vis[j] - 1) % mod;
            ans %= mod;
        }
    }

    std::cout << ans << '\n';

    return 0;
}
// 11 : 03 - 