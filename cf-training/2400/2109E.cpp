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
const int maxn = 5e2 + 5;
const ll mod = 998244353;
int n, k;
ll dp[maxn][maxn];
ll f[2][maxn][maxn];
std::string s;
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
        std::cin >> n >> k >> s;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                dp[i][j] = 0;
            }
        }
        for (int i = 0; i <= k; ++i) {
            for (int j = 0; j <= k; ++j) {
                f[0][i][j] = f[1][i][j] = 0;
            }
        
        }
        f[0][0][0] = f[1][0][0] = 1;
        for (int i = 1; i <= k; ++i) {
            for (int j = 0; j <= i; ++j) {
                for (int sgn = 0; sgn < 2; ++sgn) {
                    if (i) f[sgn][i][j] = f[sgn ^ 1][i - 1][j];
                    if (j && sgn == 0) f[sgn][i][j] += f[sgn ^ 1][i - 1][j - 1];
                    f[sgn][i][j] %= mod;
                }
            }
        }
        
        dp[0][k] = 1;
        for (int i = 0; i < n; ++i) {
            int cur = s[i] - '0';

            for (int j = 0; j <= k; ++j) {
                for (int nj = 0; nj <= j; ++nj) {
                    dp[i + 1][nj] += dp[i][j] * f[cur][j][j - nj] % mod;
                    dp[i + 1][nj] %= mod;
                }
            }
        }
        std::cout << dp[n][0] << '\n';
    }
    

    return 0;
}
