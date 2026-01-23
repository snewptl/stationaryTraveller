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
const int maxn = 2520;
const ll mod = 998244353;
ll cnt[9];
ll W;
ll dp[2][maxn + 5];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> W;
    for (int i = 1; i <= 8; ++i) {
        std::cin >> cnt[i];
    }
    dp[0][0] = 0;
    for (int i = 1; i <= maxn; ++i) {
        dp[0][i] = dp[1][i] = -1;
    }
    for (int i = 1; i <= 8; ++i) {
        ll end = maxn / i;
        for (ll j = 0; j < maxn; ++j) {
            if (dp[0][j] == -1) continue;
            for (ll k = 0; k <= std::min(cnt[i], end - 1); ++k) {
                ll new_j = (j + k * i) % maxn;
                ll new_w = dp[0][j] + k * i;
                if (new_w > W) continue;
                new_w = std::min((W - new_w) / maxn * maxn, (cnt[i] - k) / end * maxn) + new_w; 
                dp[1][new_j] = std::max(dp[1][new_j], new_w);
            }
        }
        for (int j = 0; j < maxn; ++j) {
            dp[0][j] = dp[1][j];
            dp[1][j] = -1;
        }
    }
    ll ans = 0;
    for (int i = 0; i < maxn; ++i) {
        ans = std::max(ans, dp[0][i]);
    }
    std::cout << ans << '\n';

    return 0;
}
// 15 : 43 - 