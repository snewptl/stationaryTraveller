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
ll dp[maxn], sz[maxn];
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
    if (e[u].empty()) {
        dp[u] = 1;
        return;
    }
    ll seq = 1, way = 1;
    for (auto v : e[u]) {
        dfs(v);
        sz[u] += sz[v];
        seq *= inv_fac[sz[v]], seq %= mod;
        way *= dp[v], way %= mod; 
    }
    seq *= fac[sz[u]], seq %= mod;
    dp[u] = seq * way % mod;
    for (auto v : e[u]) {
        ll new_seq = seq * fac[sz[v]] % mod * inv_fac[sz[v] + 1] % mod;
        ll new_way = way * sz[v] % mod;
        dp[u] += new_way * new_seq % mod, dp[u] %= mod;
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
    for (int i = 2; i <= n; ++i) {
        int u; std::cin >> u;
        e[u].push_back(i);
    }
    dfs(1);
    std::cout << dp[1] << '\n';
    return 0;
}
