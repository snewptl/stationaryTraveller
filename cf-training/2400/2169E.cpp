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
const int maxn = 3e5 + 5;
const ll mod = 998244353;
int n;
ll dp[maxn][16];
ll val[maxn][4];
ll x[maxn], y[maxn];
ll c[maxn];
ll sum;
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        sum = 0;
        for (int i = 1; i <= n; ++i) {
            std::cin >> x[i];
        }
        for (int i = 1; i <= n; ++i) {
            std::cin >> y[i];
        }
        for (int i = 1; i <= n; ++i) {
            std::cin >> c[i];
            sum += c[i];
        }
        for (int i = 1; i <= n; ++i) {
            val[i][0] = -x[i] * 2;
            val[i][1] = x[i] * 2;
            val[i][2] = -y[i] * 2;
            val[i][3] = y[i] * 2;
        }
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j < 16; ++j) {
                dp[i][j] = -1e18;
            }
        }
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 16; ++j) {
                for (int k = 0; k < 16; ++k) {
                    int nj = j | k;
                    if (nj != j + k) continue;
                    ll delta = k == 0 ? 0 : -c[i];

                    for (int t = 0; t < 4; ++t) {
                        if (k & (1 << t)) delta += val[i][t];
                    }
                    dp[i][nj] = std::max(dp[i][nj], dp[i - 1][j] + delta);
                }
            }
        }
        std::cout << dp[n][15] + sum << '\n';
    }

    return 0;
}