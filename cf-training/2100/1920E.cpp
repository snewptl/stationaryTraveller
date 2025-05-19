#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2500 + 5;
const ll mod = 998244353;
int n, k;
int dp[maxn][maxn];
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
        std::cin >> n >> k;
        for (int i = 0; i <= n; ++i) 
            for (int j = 0; j <= n; ++j) {
                dp[i][j] = 0;
            }
        for (int i = 0; i < k; ++i) {
            dp[0][i] = 1;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < k; ++j) {
                if (!dp[i][j]) continue;
                int new_i = i;
                for (int new_j = 0; new_j + j < k; ++new_j) {
                    new_i += j + 1;
                    if (new_i > n) break;
                    dp[new_i][new_j] += dp[i][j];
                    if (dp[new_i][new_j] >= mod) dp[new_i][new_j] -= mod;
                }
            }
        }
        ll ans = 0;
        for (int i = 0; i < k; ++i) {
            ans += dp[n][i];
            ans %= mod;
        }
        std::cout << ans << '\n';
    }

    return 0;
}
