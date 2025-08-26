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
const int maxn = 2e5 + 5;
const ll mod = 998244353;
const ll inf = 1e18;
int n;
ll a[maxn];
ll dp[maxn][3];
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
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            for (int j = 0; j < 3; ++j) {
                dp[i][j] = inf;
            }
        }
        dp[n][0] = a[n];
        dp[n][1] = a[n] - 1;
        dp[n][2] = std::max(a[n] - (n - 1), 0ll);
        for (int i = n - 1; i >= 1; --i) {
            dp[i][0] = std::min(dp[i + 1][0], dp[i + 1][2]) + a[i];
            dp[i][1] = std::min(dp[i + 1][0], dp[i + 1][1]) + a[i] - 1;
            dp[i][2] = std::min(dp[i + 1][0], dp[i + 1][1]) + std::max(a[i] - (i  -1), 0ll);
        }
        std::cout << dp[1][0] << '\n';
    }

    return 0;
}
// https://codeforces.com/contest/1614/submission/335453685
