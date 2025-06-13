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
const int maxn = 2e5 + 5;
const ll mod = 998244353;
ll dp[255][255];
ll fac[255];
ll power[255][255 * 250];
ll Cal[255][255];
int n, k;
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
    if (x < y) return 0;
    return fac[x] * inv(fac[x - y]) %mod * inv(fac[y]) % mod;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    fac[0] = 1;
    for (int i = 1; i <= 250; ++i) fac[i] = fac[i - 1] * i % mod;
    for (int i = 1; i <= 250; ++i) {
        power[i][0] = 1;
        for (int j = 1; j <= 250 * 250; ++j) {
            power[i][j] = power[i][j - 1] * i % mod;
        }
    }
    for (int i = 0; i <= 250; ++i) {
        for (int j = 0; j <= 250; ++j) {
            Cal[i][j] = C(i, j);
        }
    }
    std::cin >> n >> k;
    // for (int i = 1; i <= n; ++i) dp[2][i] = 1;
    for (int j = 1; j <= k; ++j) {
        for (int len = 1; len < n; ++len) {
            dp[len + 1][j] = Cal[n - 1][len] * power[k - j + 1][len * (len - 1) / 2 + len * 1 - len] % mod;
            dp[len + 1][j] %= mod;
        }
    }
    for (int i = 2; i < n; ++i) {
        for (int j = 1; j <= k; ++j) {
            for (int len = 1; len + i <= n; ++len) {
                for (int new_j = j + 1; new_j <= k; ++new_j) {
                    dp[i + len][new_j] += dp[i][j] * Cal[n - i][len] % mod * power[k - new_j + 1][len * (len - 1) / 2 + len * i - len] % mod;
                    dp[i + len][new_j] %= mod;
                }
                
            }
        }
    }
    ll ans = 0;
    for (int j = 1; j <= k; ++j) ans += dp[n][j], ans %= mod;
    std::cout << ans << '\n';

    return 0;
}

// 23 : 25