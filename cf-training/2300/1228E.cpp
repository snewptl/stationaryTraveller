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
const int maxn = 2e5 + 5;
const ll mod = 998244353;
int n, K;
ll pk[205];
int dp[255][255][255];
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
        std::cin >> n >> K;
        dp[1][1][1] = 1;
        dp[1][0][1] = 1;
        dp[1][1][0] = 1;
        dp[1][0][0] = K;
        pk[0] = 1;
        for (int i = 1; i <= n; ++i) pk[i] = pk[i - 1] * K % mod; 
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= n - 1; ++j) {
                for (int k = 1; k <= n - 1; ++k) {
                    dp[i][j][k] += dp[i - 1][j + 1][k + 1] * C(n - 1, j) % mod * C(n - 1, k) % mod * pk[n - 1 - j] % mod * pk[n - 1 - k] % mod; 
                }
            }
        }
    }

    return 0;
}
// 15 : 18 -          - 