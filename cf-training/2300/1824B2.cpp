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
const ll mod = 1e9  +7;
int n, k;
std::vector<std::vector<int>> e;
ll fac[maxn];
int sz[maxn];
ll ans;
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
    return fac[x] * inv(fac[y]) % mod * inv(fac[x - y]) % mod;
} 
void dfs(int u, int p) {
    sz[u] = 1;
    for (auto v : e[u]) {
        if (v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
    ans += C(sz[u], k / 2) * C(n - sz[u], k / 2);
    ans %= mod;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> k;
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = fac[i - 1] * i % mod;
    }
    e.clear();
    e.resize(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v;
        std::cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    ll bot = C(n, k);
    if (k % 2) std::cout << "1\n";
    else std::cout << (ans + bot) * inv(bot) % mod << '\n';
    

    return 0;
}
// 14 : 00 - 15 : 28 