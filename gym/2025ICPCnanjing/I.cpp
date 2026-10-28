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
const int maxn = 2e3 + 5;
const ll mod = 998244353;
int n, m;
int b[maxn], d[maxn], e[maxn];
db a[maxn], c[maxn], p[maxn];
db dp[2005][5005][2][2];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    // std::cin >> T;
    while (T--) {
        std::cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i] >> p[i];
        }
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                dp[i][j][0][0] = dp[i][j][0][1] = -1e18;
                dp[i][j][1][0] = dp[i][j][1][1] = -1e18;
            }
        }
        for (int j =  0; j <= m; ++j) {
            dp[n][j][0][0] = dp[n][j][0][1] = 0;
            dp[n][j][1][0] = dp[n][j][1][1] = 0;
        }
        for (int i = n; i >= 1; --i) {
            for (int j = 0; j <= m; ++j) {
                dp[i - 1][j][0][0] = std::max(((j >= b[i] && dp[i][j - b[i]][1][0] * (p[i] / 100) >= 0 && dp[i][j - b[i]][0][1] * (1 - p[i] / 100) >= 0) ? dp[i][j - b[i]][1][0] * (p[i] / 100) + dp[i][j - b[i]][0][1] * (1 - p[i] / 100) : -1e18) + a[i], 
                                                ((j >= d[i] && dp[i][j - d[i]][1][0] * (p[i] / 100) >= 0 && dp[i][j - d[i]][0][1] * (1 - p[i] / 100) >= 0) ? dp[i][j - d[i]][1][0] * (p[i] / 100) + dp[i][j - d[i]][0][1] * (1 - p[i] / 100) : -1e18) + c[i]);
                dp[i - 1][j][1][0] = std::max(((j >= b[i] && dp[i][j - b[i]][1][0] * (p[i] / 100) >= 0 && dp[i][j - b[i]][1][1] * (1 - p[i] / 100) >= 0) ? dp[i][j - b[i]][1][0] * (p[i] / 100) + dp[i][j - b[i]][1][1] * (1 - p[i] / 100) : -1e18) + a[i], 
                                                ((j >= d[i] && dp[i][j - d[i]][1][0] * (p[i] / 100) >= 0 && dp[i][j - d[i]][1][1] * (1 - p[i] / 100) >= 0) ? dp[i][j - d[i]][1][0] * (p[i] / 100) + dp[i][j - d[i]][1][1] * (1 - p[i] / 100) : -1e18) + c[i]);
                dp[i - 1][j][0][1] = std::max(((j >= b[i] && dp[i][j - b[i]][1][1] * (p[i] / 100) >= 0 && dp[i][j - b[i]][0][1] * (1 - p[i] / 100) >= 0) ? dp[i][j - b[i]][1][1] * (p[i] / 100) + dp[i][j - b[i]][0][1] * (1 - p[i] / 100) : -1e18) + a[i], 
                                                ((j >= d[i] && dp[i][j - d[i]][1][1] * (p[i] / 100) >= 0 && dp[i][j - d[i]][0][1] * (1 - p[i] / 100) >= 0) ? dp[i][j - d[i]][1][1] * (p[i] / 100) + dp[i][j - d[i]][0][1] * (1 - p[i] / 100) : -1e18) + c[i]);
                dp[i - 1][j][1][1] = std::max(((j >= b[i] && dp[i][j - b[i]][1][1] >= 0) ? dp[i][j - b[i]][1][1] : -1e18) + a[i], 
                                                ((j >= d[i] + e[i] && dp[i][j - d[i] - e[i]][0][0] >= 0) ? dp[i][j - d[i] - e[i]][0][0] : -1e18) + c[i]);
                // 0 1
            }
        }
        printf("%.8lf\n", (dp[0][m][0][0] < 0 ? -1 : dp[0][m][0][0]));
    }

    return 0;
}
