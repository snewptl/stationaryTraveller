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
int a[maxn];
ll count[maxn];
ll val[maxn];
ll qp(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y & 1) res *= x, res %= mod;
        x *= x, x %= mod;
        y /= 2;
    }
    return res;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> k;
        for (int i = 1; i <= n; ++i) count[i] = 0;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            for (int j = 1; j * j <= a[i]; ++j) {
                if (a[i] % j == 0) {
                    count[j] += 1;
                    if (j != a[i] / j) count[a[i] / j] += 1;
                }
            }
        }
        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
            int cur = i;
            ll res = 0;
            for (int j = 2; j * j <= cur; ++j) {
                if (cur % j == 0) {
                    res += 1;
                    while (cur % j == 0) {
                        cur /= j;
                    }
                }
            }
            if (cur != 1) res += 1;
            res = qp(res, k);
            val[i] += res;
            val[i] %= mod;
            ans += count[i] * (count[i] - 1) / 2 % mod * val[i] % mod;
            ans %= mod;
            for (int j = i * 2; j <= n; j += i) {
                val[j] -= val[i]; 
                val[j] = (val[j] + mod) % mod;
            }
        }
        std::cout << ans << '\n';
    }

    return 0;
}
// 17 : 33 - 