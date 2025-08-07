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
const ll mod = 1e9 + 7;
std::vector<std::vector<int>> e;
int n, m;
int deg[maxn], vis[maxn], size[maxn];
ll fac[maxn];
ll ans = 1;
ll dfs(int u, int p, bool is_root) {
    ll res = 1;
    vis[u] = 1;
    size[u] = 0;
    int count = 0;
    for (auto v : e[u]) {
        if (p == v) continue;
        if (vis[v]) return 0; 
        res *= dfs(v, u, 0);
        res %= mod;
        size[u] += 1;
        if (size[v] >= 1) ++count; 
    }
    if (count > 2) return 0;
    if (count == 2) {
        if (!is_root) return 0;
        res *= fac[size[u] - count] * 2;
        res %= mod;
    } else if (count == 1) {
        if (is_root) {
            res *= fac[size[u] - count] * 2;
            res %= mod;
        } else {
            res *= fac[size[u] - count];
            res %= mod;
        }
    } else {
        res *= fac[size[u]];
        res %= mod;
    }
    return res;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    fac[0] = 1;
    for (int i = 1; i <= 2e5; ++i) {
        fac[i] = fac[i - 1] * i % mod;
    }

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> m;
        e.clear();
        e.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            deg[i] = 0;
            vis[i] = 0;
            size[i] = 0;
        }
        ans = 1;
        for (int i = 1; i <= m; ++i) {
            int u, v;
            std::cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
            deg[u] += 1;
            deg[v] += 1;
        }
        int comp = 0;
        for (int i = 1; i <= n; ++i) {
            if (deg[i] == 1) continue;
            if (vis[i]) continue;
            ans *= dfs(i, 0, 1) * 2 % mod;
            ans %= mod;
            ++comp;
        }
        for (int i = 1; i <= n; ++i) {
            if (vis[i]) continue;
            ans *= dfs(i, 0, 1) * 2 % mod;
            ans %= mod;
            ++comp;
        }
        ans *= fac[comp];
        ans %= mod;
        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) ans = 0;
        }   
        std::cout << ans << '\n';
    }

    return 0;
}
