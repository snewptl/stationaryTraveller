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
const int maxn = 500 + 5;
const ll mod = 998244353;
int n, l, k;
int d[maxn];
int a[maxn];
int dp[maxn][maxn];
const int inf = 1e9 + 5;
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    // std::cin >> T;
    while (T--) {
        std::cin >> n >> l >> k;
        for (int i = 1; i <= n; ++i) {
            std::cin >> d[i];
        }
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        ++n;
        d[n] = l;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                dp[i][j] = inf;
            }
        }
        dp[1][k] = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= k; ++j) {
                for (int t = i + 1; t <= std::min(i + 1 + j, n); ++t) {
                    int delta = t - i - 1;
                    dp[t][j - delta] = std::min(dp[t][j - delta], dp[i][j] + a[i] * (d[t] - d[i]));
                }
            }
        }
        int ans = inf;
        for (int i = 0; i <= k; ++i) {
            ans = std::min(ans, dp[n][i]);
        }
        std::cout << ans << '\n';
    }

    return 0;
}
