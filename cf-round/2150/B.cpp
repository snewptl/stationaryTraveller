#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <bitset>
#include <memory.h>
#include <assert.h>
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
int a[maxn];
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

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    fac[0] = 1;
    for (int i = 1; i <= 2e5; ++i) {
        fac[i] = fac[i - 1] * i % mod;
    }

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        ll ans = 1;
        ll remain = 0;
        for (int i = n; i > (n + 1) / 2; --i) {
            if (a[i]) ans = 0;
        }
        for (int i = (n + 1) / 2; i >= 1; --i) {
            remain += 2;
            if (n % 2 && i == (n + 1) / 2) remain -= 1;
            if (remain < a[i]) ans = 0;
            ans *= C(remain, a[i]);
            ans %= mod;
            remain -= a[i];
        }
        if (remain) ans = 0;
        std::cout << ans << '\n';
    }

    return 0;
}
