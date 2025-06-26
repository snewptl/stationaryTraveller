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
const int maxn = 2e5 + 5;
const ll mod = 998244353;
int n;
struct portal {
    int x, y, s;
} p[maxn];
pii a[maxn];
ll dp[maxn], sum[maxn];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> p[i].x >> p[i].y >> p[i].s;
        a[i] = {p[i].x, i};
    }
    a[0].first = -1;
    p[0].x = -1;
    for (int i = 1; i <= n; ++i) {
        auto [pos, num] = a[i];
        if (p[num].y > a[i - 1].first) {
            dp[i] = pos - (a[i - 1].first + 1) + pos + 1 - p[num].y;
            dp[i] %= mod;
        } else {
            int it = std::lower_bound(a + 1, a + i, std::make_pair(p[num].y, 0)) - a;
            dp[i] = pos - (a[i - 1].first + 1) + sum[i - 1] - sum[it - 1] - (p[num].y - (a[it - 1].first + 1)) + a[i].first - a[i - 1].first;
            dp[i] %= mod;
        }
        sum[i] = sum[i - 1] + dp[i];
        sum[i] %= mod;
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (p[i].s) ans += dp[i];
        else ans += p[i].x - p[i - 1].x;
        ans %= mod;
    }
    std::cout << (ans + mod) % mod << '\n';
    

    return 0;
}
// 9 : 35 - 10 : 23
