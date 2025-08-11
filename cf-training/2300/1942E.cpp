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
const int maxn = 1e6 + 5;
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
    return fac[x] * inv(fac[y]) %mod * inv(fac[x - y]) % mod;
} 
int n, l;
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    fac[0] = 1;
    for (int i = 1; i <= 1e6; ++i) {
        fac[i] = fac[i - 1] * i % mod;
    }

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> l >> n;
        ll sum = C(l, n * 2);
        for (int i = 0; i <= l - n * 2; i += 2) {
            int pair = i / 2;
            sum -= C(n + pair - 1, n - 1) * C(n + 1 + l - i - n * 2 - 1, n + 1 - 1) % mod;
            sum %= mod;
        }
        sum *= 2;
        sum %= mod;
        std::cout << (sum + mod) % mod << '\n';
    }

    return 0;
}
// 22 : 57 - 23 : 42

/*
0 houshou

1, k xianshou

k + 1 houshou

k + 2, k * 2 + 1 xianshou

k * 2 + 2 houshou

k + 1 beishu houshou

fouze xainshou
*/