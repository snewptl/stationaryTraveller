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
const int maxn = 1e6 + 5;
const ll mod = 998244353;
const ll inf = 1e18;
ll dp[3][maxn];
int n;
ll d;
ll r[4], a[maxn];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for (int i = 1; i <= 3; ++i) std::cin >> r[i];
    std::cin >> d;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    dp[2][0] = 0;
    dp[0][0] = dp[1][0] = inf;
    for (int i = 1; i <= n; ++i) {
        ll attack_once = r[1] * a[i] + r[3];
        ll attack_twice = std::min((a[i] + 1) * r[1], r[2]) + r[1];
        dp[2][i] = std::min(std::min(dp[1][i - 1], dp[0][i - 1]), dp[2][i - 1]) + attack_once + d;
        if (i == n) dp[2][i] = std::min(dp[2][i], dp[1][i - 1] + attack_once);
        dp[0][i] = std::min(dp[1][i - 1] + d + attack_twice, inf);
        dp[1][i] = std::min(dp[0][i - 1], dp[2][i - 1]) + 3 * d + attack_twice;
    }
    std::cout << std::min(std::min(dp[0][n], dp[1][n]), dp[2][n]) - d << '\n';

    return 0;
}
// 11 : 13 - 12 : 28
// 15 : 40 - 15 : 59
