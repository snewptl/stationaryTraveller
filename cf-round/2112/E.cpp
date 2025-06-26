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
const int maxn = 5e5;
const ll mod = 998244353;
int dp[21][maxn + 5];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    for (int i = 1; i <= 20; ++i) {
        for (int j = 1; j <= maxn; ++j) dp[i][j] = 1e9;
    }

    for (int i = 1; i * 2 + 1 <= maxn; ++i) dp[1][i * 2 + 1] = i + 1;
    dp[1][1] = 1;

    for (int i = 2; i <= 20; ++i) {
        for (int j = 1; j <= maxn; ++j) {
            for (int k = j * 2 + 1; k <= maxn; k += j * 2 + 1) {
                dp[i][k] = std::min(dp[i][k], dp[i - 1][k  / (j * 2 + 1)] + j);
            }       
        }
        for (int j = 1; j <= maxn; ++j) {
            dp[i][j] = std::min(dp[i][j], dp[i - 1][j]);
        }
    }
    int T = 1;
    std::cin >> T;
    while (T--) {
        int m;
        std::cin >> m;
        std::cout << (dp[20][m] == 1e9 ? -1 : dp[20][m]) << '\n';
    }

    return 0;
}
