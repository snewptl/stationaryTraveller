#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <string.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
int n, m, k;
ll dp[205][205], a[205][205];
void solve() {
    dp[0][1] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int t = 0; t < m; ++t) {
            ll b[205];
            memset(b, 0x7f, sizeof(b));
            for (int  j = 1; j <= m; ++j) {
                int newj = (j + t - 1) % m + 1;
                b[j] = std::min(b[j - 1], dp[i - 1][j]) + a[i][newj];
            }
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = std::min(dp[i][j], b[j] + 1ll * k * t);
            }
        }
    }
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
            for (int  j = 1; j <= m; ++j) {
                std::cin >> a[i][j];
            }
        }
        memset(dp, 0x7F, sizeof(dp));
        solve();
        std::cout << dp[n][m] << '\n';
    }

    return 0;
}
