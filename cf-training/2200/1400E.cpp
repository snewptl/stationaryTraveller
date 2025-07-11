#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <assert.h>
#include <cmath>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 5e3 + 5;
ll dp[maxn][maxn];
int n;
ll a[maxn];
ll inv[maxn];
std::map<ll, int> mp;
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n;
    std::vector<ll> vec;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        if (a[i]) vec.push_back(a[i]);
    }
    sort(all(vec));
    vec.resize(std::unique(all(vec)) - vec.begin());
    for (int i = 0; i < vec.size(); ++i) {
        mp[vec[i]] = i + 1;
        inv[i + 1] = vec[i];
    }
    
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= vec.size(); ++j) {
            dp[i][j] = 1e18;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 0) {
            ll min = 1e18;
            for (int j = 0; j <= vec.size(); ++j) {
                min = std::min(min, dp[i - 1][j]);
            }
            dp[i][0] = min;
            continue;
        }
        int cur = mp[a[i]];
        int pre = a[i - 1] ? mp[a[i - 1]] : 0;
        ll min = 1e18;
        if (pre >= cur) {
            for (int j = pre; j >= cur; --j) {
                min = std::min(dp[i - 1][j], min);
            }
            dp[i][cur] = min;
            for (int j = cur - 1; j >= 0; --j) {
                dp[i][j] = dp[i -  1][j] + 1;
            }
        } else {
            for (int j = 0; j <= pre; ++j) {
                dp[i][j] = dp[i - 1][j] + 1;
            }
            for (int j = pre + 1; j <= cur; ++j) {
                dp[i][j] = dp[i - 1][pre] + inv[j] - inv[pre] + (j < cur);
            }
        }
    }
    ll ans = 1e18;
    for (int i = 0; i <= vec.size(); ++i) ans = std::min(ans, dp[n][i]);
    std::cout << ans << '\n';

    return 0;
}
// 21 : 18 - 