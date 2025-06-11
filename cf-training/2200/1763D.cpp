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
const int maxn = 105;
const ll mod = 1e9 + 7;
ll fac[maxn];
int n, i, j, x, y;
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
ll C(int x, int y) {
    if (x < 0 || y < 0) return 0;
    if (x < y) return 0;
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
    for (int i = 1; i <= 100; ++i) fac[i] = fac[i - 1] * i % mod;
    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> i >> j >> x >> y;
        if (x > y) {
            i = n - i + 1;
            j = n - j + 1;
            std::swap(i, j);
            std::swap(x, y);
        }
        ll ans = 0;
        if (y == n) {
            ans += C(x - 1, i - 1) * C(n - 1 - x, j - i - 1) % mod;
            ans %= mod;
            if (j == n) ans = 0;
        } else {
            int len_j = n - j + 1;
            for (int k = i + 1; k < j; ++k) {
                ans += C(x - 1, i - 1) * C(y - x - 1, len_j - 1 - (x - i)) % mod * C(n - y - 1, j - k - 1) % mod;
                ans %= mod;
            }
            for (int k = j + 1; k < n; ++k) {
                ans += C(x - 1, i - 1) * C(y - x - 1, j - i - 1) % mod * C(n - y - 1, k - j - 1) % mod;
                ans %= mod;
            }
        }

        std::cout << ans << '\n';
    }

    return 0;
}

// 10 : 20

// i x 
// j y
// k n

// t in [0, y - x - 1]

// x < y 

// i < k < j
// C(x - 1, i - 1) * C(x - i, len_j - 1 - t) * C(y - x - 1, t) * C(n - x - 1 - 1 - (y - x - 1 - t), k - i - 1 - (y - x - 1 - t));