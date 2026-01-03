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
std::vector<std::vector<int>> e;
int n;
int even[maxn];
int size[maxn];
ll ans = 1;
int count = 0;
ll fin = 1;
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
void dfs(int u, int p) {
    size[u] = 1;
    for (auto v : e[u]) {
        if (v == p) continue;
        dfs(v, u);
        size[u] += size[v];
    }
    if (u != 1 && size[u] % 2 == 0) ans *= 1ll * size[u], ans %= mod, count += 1;
    if (size[u] % 2 == 0 || u == 1) ans *= size[u], ans %= mod;
    if (size[u] % 2 == 0) size[u] = 0;
}
void dfs2(int u, int p) {
    size[u] = 1;
    for (auto v : e[u]) {
        if (v == p) continue;
        dfs2(v, u);
        size[u] += size[v];
    }
    if (u != 1 && size[u] % 2 == 0) fin += ans * inv(size[u]) % mod, fin %= mod;
    if (size[u] % 2 == 0) size[u] = 0;
}
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
        e.clear();
        e.resize(n + 1);
        ans = 1;
        fin = 0;
        count = 0;
        for (int i = 1; i < n; ++i) {
            int u, v;
            std::cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(1, 0);
        for (int i = 1; i <= count - 1; ++i) ans *= i, ans %= mod;
        dfs2(1, 0);
        if (fin == 0) fin = 1;
        std::cout << fin << '\n';
    }

    return 0;
}
