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
const int maxn = 5e3 + 5;
ll mod = 998244353;
int n;
ll dp[maxn][maxn];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> mod;
        for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            dp[i][j] = 0;
        dp[n][1] = 1;
        dp[n][0] = n;
        for (int i = n - 1; i >= 1; --i) {
            for (int j = 0; j <= n - i + 1; ++j) {
                if (j) dp[i][j] = dp[i + 1][j - 1];
                if (j <= n - i) dp[i][j] += 1ll * dp[i + 1][j] * (j + 1) % mod * i % mod;
                dp[i][j] %= mod;
            } 
        }
        ll ans = 0;
        for (int i = 0; i <= n; ++i) ans += dp[1][i], ans %= mod;
        std::cout << ans << '\n';
    }

    return 0;
}
