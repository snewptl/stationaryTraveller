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
const int maxn = 4e3 + 5;
const ll mod = 998244353;
int n, k;
ll f[maxn][maxn], sum[maxn][maxn];
ll power[maxn], dp[maxn];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> k;

    power[0] = 1;
    for (int i = 1; i <= n; ++i) {
        power[i] = power[i - 1] * k % mod;
    }
    
    f[1][1] = k;
    sum[1][1] = k;
    for (int i = 1; i < n; ++i) {
        for (int j = k - 1; j >= 1; --j) {
            f[i + 1][j] = sum[i][j];
            f[i + 1][j + 1] += f[i][j] * (k - j);
            f[i + 1][j + 1] %= mod;
        }
        for (int j = k - 1; j >= 1; --j) {
            sum[i + 1][j] = f[i + 1][j];
            if (j < k - 1) sum[i + 1][j] += sum[i + 1][j + 1], sum[i + 1][j] %= mod;
        }
    }
    ll ans = 0;
    dp[0] = 1;
    for (int i = k; i <= n; ++i) {
        for (int j = k; j <= i; ++j) {
            dp[i] += dp[i - j] * f[j][k];
            dp[i] %= mod;
        }
        ans += dp[i] * power[n - i];
        ans %= mod;
    }
    std::cout << ans << '\n';
    return 0;
}
// 9 : 22 - 10 : 08
/*
1 2 3 4 3 2 1 2 3 4

*/