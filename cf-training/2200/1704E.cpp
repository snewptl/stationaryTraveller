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
const int maxn = 1e3 + 5;
const ll mod = 998244353;
int n, m;
std::vector<std::vector<int>> e, g;
ll a[maxn];
int in[maxn];
int dfn[maxn];
int dfn_num;
ll dp[maxn];
int vis[maxn];
void topo() {
    std::queue<int> q;
    for (int i = 1; i <= n; ++i) if (in[i] == 0) q.push(i), dfn[++dfn_num] = i;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : e[u]) {
            --in[v];
            if (in[v] == 0) q.push(v), dfn[++dfn_num] = v;
        }
    }
}
void dfs(int u) {
    dp[u] = a[u];  
    for (auto v : g[u]) {
        if (!vis[v]) dfs(v);
        vis[v] = 1;
        dp[u] += dp[v];
        dp[u] %= mod;
    }   
}
void solve() {
    for (int i = 1; i <= n; ++i) {
        int flag = 0;
        for (int j = 1; j <= n; ++j) if (a[j] >= 1) flag = 1;
        if (!flag) {
            std::cout << i - 1 << '\n';
            return;
        }
        std::vector<int> vec;
        for (int j = n; j >= 1; --j) {
            if (a[dfn[j]]) vec.push_back(dfn[j]);
        }
        for (auto u : vec) {
            for (auto v : e[u]) {
                a[v] += 1;
            }
            a[u] -= 1;
        }
    }
    dfs(dfn[n]);
    std::cout << (n + dp[dfn[n]]) % mod << '\n';
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
        std::cin >> n >> m;
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        e.clear();
        e.resize(n + 1);
        g.clear();
        g.resize(n + 1);
        dfn_num = 0;
        for (int i = 1; i <= n; ++i) {
            dfn[i] = 0;
            dp[i] = 0;
            in[i] = 0;
            vis[i] = 0;
        }
        for (int i = 1; i <= m; ++i) {
            int u, v, w;
            std::cin >> u >> v;
            e[u].push_back(v);
            g[v].push_back(u);
            in[v] += 1;
        }
        topo();
        solve();
    }

    return 0;
}

// 10 : 45