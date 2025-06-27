#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <assert.h>
#include <cmath>
#include <memory.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 5e2 + 5;
const ll mod = 998244353;
int n;
ll dp[maxn][maxn];
ll power[maxn];
pii a[maxn];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    power[0] = 1;
    for (int i = 1; i <= 500; ++i) power[i] = power[i - 1] * 2 % mod;

    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::string str;
        int x;
        std::cin >> str;
        if (str[0] == '-') {
            a[i] = {0, 0};
        } else {
            std::cin >> x;
            a[i] = {1, x};
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i].first == 0) continue;
        memset(dp, 0, sizeof(dp));
        // dp[i][0] = power[i - 1] * a[i].second % mod;
        dp[0][0] = 1;
        for (int j = 0; j < n; ++j) {
            if (j + 1 == i) {
                for (int k = 0; k <= n; ++k) dp[j + 1][k] = dp[j][k]; 
                continue;
            } 
            if (!a[j + 1].first) {
                for (int k = 1; k <= n; ++k) {
                    dp[j + 1][k] = dp[j][k] + dp[j][k + 1];
                    dp[j + 1][k] %= mod;
                }
                if (j + 1 < i) {
                    dp[j + 1][0] = dp[j][1] + dp[j][0] * 2;
                    dp[j + 1][0] %= mod;
                } else {
                    dp[j + 1][0] = dp[j][1] + dp[j][0];
                    dp[j + 1][0] %= mod;
                }

            } else {
                for (int k = 0; k <= n; ++k) {
                    if (a[j + 1].second < a[i].second || (a[j + 1].second == a[i].second && j + 1 > i)) {
                        dp[j + 1][k] = dp[j][k];
                        if (k) dp[j + 1][k] += dp[j][k - 1];
                    } else {
                        dp[j + 1][k] = dp[j][k] * 2;
                    }
                    dp[j + 1][k] %= mod;
                }
            }
        }
        for (int j = 0; j <= n; ++j) ans += dp[n][j] * a[i].second % mod, ans %= mod;
    }
    std::cout << ans << '\n';

    return 0;
}

// 20 : 40 - 21 : 39