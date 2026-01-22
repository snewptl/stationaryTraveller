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
int m;
ll val[maxn], vis[maxn];
ll p2 (ll x) {
    return x * x % mod;
}
ll qp(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y & 1) res *= x, res %= mod;
        x *= x, x %= mod;
        y /= 2;
    }
    return res;
}
ll inv(ll x) {
    return qp(x, mod - 2);
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> m;
    for (int i = 2; i <= m; ++i) {
        if (!vis[i]) val[i] = 1;
        ll p = m / i * inv(m) % mod;
        ll r = p * p2(inv(1 - p)) % mod;
        for (int j = i * 2; j <= m; j += i) {
            val[i] -= val[j]; 
        }
    }
    return 0;
}
// 18 : 30 - 