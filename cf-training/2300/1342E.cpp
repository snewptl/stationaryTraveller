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
ll fac[maxn];
ll quick_pow(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y & 1) res *= x, res %= mod;
        x *= x, x %= mod;
        y /= 2;
    }
    return res;
}
ll inv(ll x) {
    return quick_pow(x, mod - 2);
}
ll C(ll x, ll y) {
    if (y > x) return 0;
    return fac[x] * inv(fac[y]) % mod * inv(fac[x - y]) % mod;
} 
ll A(ll x, ll y) {
    if (y > x) return 0;
    return fac[x] * inv(fac[y]) % mod;
}
int n, k;
int f[maxn];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    fac[0] = 1;
    for (int i = 1; i <= 2e5; ++i) {
        fac[i] = fac[i - 1] * i % mod;
    }
    std::cin >> n >> k;
    ll ans = 1;
    int col = n - k;
    if (col <= 0) ans = 0;
    else if (col == n) {
        ans = fac[n];
    } else {
        f[1] = 1;
        ll sum = 1;
        for (int i = 2; i <= n; ++i) {
            f[i] = quick_pow(i, n);
            f[i] = (f[i] - sum * fac[i] % mod + mod) % mod;
            sum = (sum * inv() + f[i] * inv(fac[i]) % mod) % mod;
        }
        ans = C(n, col) % mod * f[col] % mod * 2 % mod;
    }
    std::cout << ans << '\n';
    
    return 0;
}
// 20 : 38 - 