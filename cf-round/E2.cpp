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
const int maxn = (1 << 20) + 5;
const ll mod = 1e9 + 7;
int n, k;
ll m;
ll dp[21][maxn];
int vis[21];
ll quick_pow(ll x, ll y) {
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
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> m >> k;
        for (int i = 1; i <= n; ++i) {
            vis[i] = 0;
            for (int j = 1; j < (1 << i); ++j) {
                dp[i][j] = 0;
            }
        }
        for (int i = 1; i <= k; ++i) {
            int x; std::cin >> x;
            vis[x] = 1;
        }
        dp[1][1] = 1;
        for (int i = 2; i <= n; ++i) {
            int turn = (n - i) % 2;
            for (int j = 1; j < (1 << i); ++j) {
                dp[i][j] = turn;
                int l = j, r = 0;
                for (int t = i; t >= 1; --t) {
                    int add = 0;
                    if ((1 << (t - 1)) & j) {
                        l -= 1 << (t - 1);
                        if (t >= 2) add = 1 << (t - 2);
                    }
                    if (vis[t]) {
                        if (!turn) dp[i][j] |= dp[i - 1][l + r];
                        else dp[i][j] &= dp[i - 1][l + r];
                    }
                    r += add;
                }
            }
        }
        ll ans = quick_pow(m, n);
        std::vector<int> count;
        count.resize(n + 1);
        for (int i = 1; i < (1 << n); ++i) {
            if (!dp[n][i]) continue;
            int cur = i, num = 0;
            while (cur) {
                if (cur & 1) num += 1;
                cur /= 2;
            }
            count[num] += 1;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 2; j <= m; ++j) {
                ans += count[i] * quick_pow(m - j + 1, i) % mod * quick_pow(j - 1, n - i) % mod;
                ans %= mod;
            }

        }
        std::cout << ans << '\n';
        
    }

    return 0;
}
