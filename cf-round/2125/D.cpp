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
int n, m;
ll dp[maxn];
std::pair<pii, pll> seg[maxn];
ll quick_pow(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y & 1) res *= x, res %= mod;
        x *= x, x %= mod;
        y /= 2;
    }
    return res;
}
ll inv(ll x) {
    return quick_pow(x, mod - 2);
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> m >> n;
    dp[0] = 1;
    for (int i = 1; i <= m; ++i) {
        std::cin >> seg[i].first.first >> seg[i].first.second >> seg[i].second.first >> seg[i].second.second;
        dp[0] *= (seg[i].second.second - seg[i].second.first) * inv(seg[i].second.second) % mod;
        dp[0] %= mod;
    }
    std::sort(seg + 1, seg + m + 1);

    for (int i = 1; i <= m; ++i) {
        auto [l, r] = seg[i].first;
        auto [p, q] = seg[i].second;
        dp[r] += dp[l - 1] * inv((q - p) * inv(q) % mod) % mod * p % mod * inv(q) % mod;
        dp[r] %= mod;
    }    
    std::cout << dp[n] << '\n';

    return 0;
}
