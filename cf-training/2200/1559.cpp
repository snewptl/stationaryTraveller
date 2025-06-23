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
const int maxn = 1e5 + 5;
const ll mod = 998244353;
int n, m;
int count[maxn];
int dp[51][maxn];
pii a[51];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int l, r;
        std::cin >> l >> r;
        a[i] = {l, r};
    }
    ll ans = 0;
    for (int gcd = 1; gcd <= m; ++gcd) {
        int delta = (gcd == 1 ? 1 : -count[gcd]);
        if (gcd != 1 && !delta) continue;
        int flag = 1;
        for (int i = 0; i <= m; ++i) dp[0][i] = delta;
        for (int i = 1; i <= n; ++i) {
            int start = (a[i].first + gcd - 1) / gcd;
            int end = a[i].second / gcd;
            if (start > end) flag = 0;
            int last = m / gcd;
            for (int j = start; j <= last; ++j) {
                if (j) dp[i][j] = dp[i][j - 1];
                dp[i][j] += dp[i - 1][j - start];
                if (j > end) dp[i][j] -= dp[i - 1][j - end - 1];
                if (dp[i][j] >= mod) dp[i][j] -= mod;
                else if (dp[i][j] < 0) dp[i][j] += mod;
            }
        }
        if (flag) {
            for (int i = gcd; i <= m; i += gcd) {
                count[i] += delta;
            }
            ans += dp[n][m / gcd];
            ans %= mod;
        }
    }
    std::cout << (ans + mod) % mod << '\n';

    return 0;
}
// 19 : 06 - 