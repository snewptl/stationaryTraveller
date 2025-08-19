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
const int maxn = 1e5 + 5;
const ll mod = 998244353;
ll fac[maxn * 2];
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
int n, a[maxn];
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
        int l = 1, r = n;
        int is_begin = 1;
        ll sum[2] = {0, 0};
        
        while (l <= r) {
            int zero[2] = {0, 0};
            if (a[l] == 0 || a[r] == 0) {
                while (l <= r && a[l] == 0) {
                    zero[0] += 1;
                    ++l;
                }
                while (l <= r && a[r] == 0) {
                    zero[1] += 1;
                    --r;
                }
                if (l > r) {
                    int max = std::max(zero[0], zero[1]);
                    if (is_begin) {
                        ans *= quick_pow(2, max - 1);
                        ans %= mod;
                    } else {
                        ans *= quick_pow(2, max + 1);
                        ans %= mod;
                    }
                } else {
                    int min = std::min(zero[0], zero[1]);
                    ll tot = 0;
                    if (is_begin) {
                        for (int j = 0; j <= min; ++j) {
                            tot += C(zero[0], j) * C(zero[1], j) % mod;
                            tot %= mod;
                        }
                    } else {
                        tot += 1;
                        for (int j = 0; j <= min; ++j) {
                            tot += C(zero[0] + 1, j + 1) * C(zero[1] + 1, j + 1) % mod;
                            tot %= mod;
                        }
                    }
                    ans *= tot;
                    ans %= mod;
                }
            } else {
                if (!is_begin) {
                    ans *= 2;
                    ans %= mod;
                }
            } 
            if (l > r) break;
            sum[0] += a[l];
            l++;
            while (l <= r) {
                if (sum[0] < sum[1]) {
                    sum[0] += a[l];
                    ++l;
                } else if (sum[0] > sum[1]) {
                    sum[1] += a[r];
                    --r;
                } else {
                    break;
                }
            } 
            if (l > r && sum[0] == sum[1]) {
                ans *= 2;
                ans %= mod;
            } 
            is_begin = 0;
        }
        std::cout << ans << '\n';
    }

    return 0;
}
// 10 : 44 - 