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
int n;
std::vector<std::vector<int>> e;
int leaf[maxn], dfn[maxn], dep[maxn], son[maxn], fa[maxn], rk[maxn], count;
int vis[maxn];
ll dp[maxn];
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
    int num_son = 0;
    leaf[u] = n;
    fa[u] = p;
    dfn[u] = ++count;
    rk[count] = u;
    for (auto v : e[u]) {
        if (v == p) continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
        if (leaf[u] > leaf[v]) {
            leaf[u] = leaf[v];
            son[u] = v;
        }
        ++num_son;
    }
    if (!num_son) leaf[u] = dep[u], son[u] = 0;
}
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
        std::cin >> n;
        count = 0;
        e.clear();
        e.resize(n + 1);
        for (int i = 1; i <= n; ++i) vis[i] = 0;
        for (int i = 1; i < n; ++i) {
            int u, v;
            std::cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(1, 0);
        dp[1] = 1;
        for (int i = 1; i <= n; ++i) {
            std::vector<int> path;
            int cur = rk[i];
            int top = (cur == 1 ? 1 : fa[cur]);
            if (vis[cur]) continue;
            while (cur) {
                assert(!vis[cur]);
                if (cur != 1) path.push_back(cur);
                vis[cur] = 1;
                cur = son[cur];
            }
            int len = path.size();
            for (int i = 0; i < len; ++i) {
                dp[path[i]] = dp[top] * (len - i - 1) % mod * inv(len) % mod;
            }
        }
        for (int i = 1; i <= n; ++i) {
            std::cout << dp[i] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
// 17 : 40 - 18 : 30