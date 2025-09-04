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
const ll mod = 1e9 + 7;
int n;
int dep[maxn];
std::vector<std::vector<int>> e;
ll fac[maxn], inv_fac[maxn];
int fa[maxn][10];
ll f[205][205];
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
    if (y > x || y < 0) return 0;
    assert(x >= 0);
    assert(x <= 2 * n);
    assert(y <= 2 * n);
    return fac[x] * inv_fac[y] % mod * inv_fac[x - y] % mod;
} 
void dfs(int u, int p) {
    fa[u][0] = p;
    for (auto v : e[u]) {
        if (v == p) continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}
int lca(int u, int v) {
    if (dep[u] < dep[v]) std::swap(u, v);
    for (int i = 9; i >= 0; --i) {
        if (dep[fa[u][i]] >= dep[v]) {
            u = fa[u][i];
        }
    }
    for (int i = 9; i >= 0; --i) {
        if (fa[u][i] != fa[v][i]) {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    if (u != v) u = fa[u][0], v = fa[v][0];
    assert(u == v);
    return u;
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
    for (int i = 1; i <= n * 2; ++i) {
        fac[i] = fac[i - 1] * i % mod;
    }
    inv_fac[n * 2] = inv(fac[n * 2]);
    for (int i = n * 2 - 1; i >= 0; --i) {
        inv_fac[i] = inv_fac[i + 1] * (i + 1) % mod;
    }

    for (int j = 0; j <= n; ++j) {
        f[0][j] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        f[i][0] = 1;
        for (int j = 1; j <= n; ++j) {
            f[i][j] = inv(2) * (f[i - 1][j] + f[i][j - 1]) % mod;
        }
    }

    e.resize(n + 1);

    for (int i = 1; i < n; ++i) {
        int u, v;
        std::cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    ll inv_n = inv(n);
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        dep[i] = 1;
        dfs(i, 0);
        for (int j = 1; j < 10; ++j) {
            for (int k = 1; k <= n; ++k) {
                fa[k][j] = fa[fa[k][j - 1]][j - 1];
            }
        }
        for (int j = 1; j <= n; ++j) {
            for (int k = j + 1; k <= n; ++k) {
                int top = lca(j, k);
                // int balls = dep[k] - dep[top], places = dep[j] - dep[top];
                // ll inv_count = C(places + balls - 1, places - 1);
                // ll all_count = C(places + balls + 1 - 1, places + 1 - 1);
                // ans += inv_count * inv(all_count) % mod;
                // ans %= mod;
                ans += f[dep[j] - dep[top]][dep[k] - dep[top]];
                ans %= mod;
            }
        }

    }
    ans *= inv_n;
    ans %= mod;
    std::cout << ans << '\n';
    

    return 0;
}
// 12 : 00 - 12 : 47