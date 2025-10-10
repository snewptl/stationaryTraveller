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
const int maxn = 1e5 + 5;
const ll mod = 998244353;
int n;
std::vector<std::vector<int>> e;
std::vector<std::vector<ll>> dp;
ll sz[maxn];
ll fac[maxn], inv_fac[maxn];
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
ll C(ll x, ll y) {
    if (y > x) return 0;
    return fac[x] * inv_fac[y] % mod * inv_fac[x - y] % mod;  
} 
void dfs(int u) {
    sz[u] = 1;
    for (auto v : e[u]) {
        dfs(v);
        sz[u] += sz[v];
    }
    dp[u].resize(sz[u], 0);
    dp[u][0] = 1;
    int sum = 0;
    for (auto v : e[u]) {
        for (int i = sum; i >= 0; --i) {
            for (int j = sz[v] - 1; j >= 0; --j) {
                
            }
        }
    }
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = fac[i - 1] * i % mod;
    }
    inv_fac[n] = inv(fac[n]);
    for (int i = n - 1; i >= 0; --i) {
        inv_fac[i] = inv_fac[i + 1] * (i + 1) % mod;
    }
    e.clear();
    e.resize(n + 1);
    dp.clear();
    dp.resize(n + 1);
    for (int i = 2; i <= n; ++i) {
        int u; std::cin >> u;
        e[u].push_back(i);
    }
    dfs(1);
    std::cout << dp[1] << '\n';
    return 0;
}
