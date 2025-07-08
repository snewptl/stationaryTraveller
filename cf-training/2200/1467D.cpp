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
const int maxn = 5e3 + 5;
const ll mod = 1e9 + 7;
int n, k, q;
ll a[maxn];
ll dp[maxn][maxn], f[maxn][maxn];
ll fac[maxn];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> k >> q;
    for (int i = 1; i <= n; ++i) std::cin >> a[i]; 
    for (int i = 1; i <= n; ++i) f[0][i] = 1;
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (j > 1) f[i][j] += f[i - 1][j - 1];
            if (j < n) f[i][j] += f[i - 1][j + 1];
            f[i][j] %= mod;
        }
    }
    for (int i = 1; i <= n; ++i) dp[0][i] = 1;
    ll sum = 0;
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (j > 1) dp[i][j] += dp[i - 1][j - 1];
            if (j < n) dp[i][j] += dp[i - 1][j + 1];
            dp[i][j] %= mod;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            fac[i] += dp[j][i] * dp[k - j][i] % mod;
            fac[i] %= mod;
        }
    }
    for (int i = 1; i <= n; ++i) {
        sum += fac[i] * a[i] % mod;
    }
    for (int i = 1; i <= q; ++i) {
        int id, x;
        std::cin >> id >> x;
        sum -= a[id] * fac[id] % mod;
        a[id] = x;
        sum += a[id] * fac[id] % mod;
        sum = (sum % mod + mod) % mod; 
        std::cout << sum << '\n';
    }
    
    return 0;
}
// 18 : 41 - 