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
const int maxn = 3e6 + 5;
ll mod;
int n;
ll fac[maxn], inv_fac[maxn];
ll phase[4];
ll quick_pow(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y & 1) res *= x, res %= mod;
        x *= x, x %= mod;
        y /= 2;
    }
    return res;
}
ll C(ll x, ll y) {
    if (y > x) return 0;
    return fac[x] * inv_fac[y] % mod * inv_fac[x - y] % mod;
} 
ll inv(ll x) {
    return quick_pow(x, mod - 2);
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> mod;
    fac[0] = 1;
    for (int i = 1; i <= 3 * n; ++i) {
        fac[i] = fac[i - 1] * i % mod;
    }
    inv_fac[3 * n] = inv(fac[n * 3]);
    for (int i = 3 * n - 1; i >= 0; --i) {
        inv_fac[i] = inv_fac[i + 1] * (i + 1) % mod;
    }
    phase[0] = 1;
    phase[1] = fac[2 * n] * 2 - fac[n] - 1;
    phase[1] = (phase[1] % mod + mod) % mod;
    phase[2] = fac[2 * n] * inv_fac[n] % mod * fac[2 * n] * 2 % mod;
    ll delta = 0;
    for (int i = 0; i <= n; ++i) {
       delta += C(n, i) * fac[n] % mod * C(n, n - i) % mod * C(2 * n - i, n) % mod * fac[n] % mod * fac[n] % mod;
       delta %= mod;
    }
    phase[2] -= delta;
    phase[2] -= (phase[1] + phase[0]);
    phase[2] = (phase[2] % mod + mod) % mod;
    phase[3] = (fac[3 * n] - (phase[2] + phase[1] + phase[0]) % mod + mod) % mod;
    ll ans = 0;
    for (int i = 0; i < 4; ++i) {
        ans += i * phase[i];
        ans %= mod;
    }
    std::cout << ans << '\n';

    return 0;
}
// 16 : 30 - 17 : 17