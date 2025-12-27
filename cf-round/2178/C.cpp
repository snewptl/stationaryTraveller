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
const ll inf = 1e18;
int n;
ll a[maxn];
ll dp[maxn];
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
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        ll max = -inf;
        for (int i = 1; i <= n; ++i) {
            max = std::max(max - a[i], a[i] + dp[i - 1]);
            dp[i] = max;
        }
        ll ans = -inf, last = 0;
        for (int i = n; i >= 1; --i) {
            ll temp = dp[i - 1] + last + a[i];
            last -= a[i];
            if (i == n) temp -= a[n];
            else temp = std::max(temp - a[i], temp + a[n]);
            ans = std::max(ans, temp);
        }
        std::cout << ans << '\n';
    }

    return 0;
}
