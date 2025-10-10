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
const int maxn = 3e6 + 5;
const ll mod = 998244353;
ll a, b, m;
ll dp[maxn], f[maxn];
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
        std::cin >> a >> b >> m;
        for (int i = 0; i <= m; ++i) {
            f[i] = (m - i) / a;
            dp[i] = f[i];
        }
        dp[0] = 2 + f[0];
        ll new_a = a;
        while (new_a < b) new_a += a; 
        ll ans = 0;
        for (int i = 0; i <= m; ++i) {
            dp[i + 1] = std::max(dp[i + 1], dp[i] - f[i] + f[i + 1]);
            dp[i + b] = std::max(dp[i + b], dp[i] - f[i] + f[i + b] + (b / a + 1));
            dp[i + new_a] = std::max(dp[i + new_a], dp[i] - f[i] + f[i + new_a] + (new_a / a + 1));
            ans = std::max(ans, dp[i]);
        }
        std::cout << ans * 160 << '\n';
    }

    return 0;
}
