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
pll dp[505][505];
ll e[505][505];
int n, m;
pll add(pll x, ll y) {
    return {x.first + std::min(x.second, y), std::min(x.second, y)};
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
        std::cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = {1e18, 1e18};
                e[i][j] = 1e18;
            }
        }
        for (int i = 1; i <= m; ++i) {
            int u, v, w;
            std::cin >> u >> v >> w;
            dp[u][v] = dp[v][u] = {w, w};
            e[u][v] = e[v][u] = w;
        }
        for (int i = 1; i <= n; ++i) {
            for (int k = 1; k <= n; ++k) {
                for (int j = 1; j <= n; ++j) {
                    if (e[i][k] == 1e18) continue;
                    if (add(dp[i][j], e[i][k]) < dp[j][k]) {
                        pll res = add(dp[i][j], e[i][k]);
                        dp[j][k] = dp[k][j] = res;
                    }
                } 
            }
        }

        std::cout << dp[1][n].first << '\n';
    }

    return 0;
}

// 14 : 40