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
int n, m;
// std::vector<std::vector<int>> g;
std::vector<std::vector<pii>> e, g;
int vis[maxn], val[maxn];
int flag;
void dfs(int u) {
    for (auto [v, w] : g[u]) {
        if (vis[v]) {
            if (val[v] ^ val[u] != w) flag = 0;
        } else {
            vis[v] = 1;
            val[v] = val[u] ^ w;
            dfs(v);
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

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> m;
        e.clear();
        e.resize(n + 1);
        g.clear();
        g.resize(n + 1);
        flag = 1;
        for (int i = 1; i <= n; ++i) {
            vis[i] = val[i] = 0;
        }
        for (int i = 1; i < n; ++i) {
            int u, v, w;
            std::cin >> u >> v >> w;
            e[u].push_back({v, w});
            e[v].push_back({u, w});
            if (w != -1) {
                int count = 0;
                for (int j = 0; j < 30; ++j) {
                    if ((1 << j) & w) ++count;
                }
                g[u].push_back({v, count % 2});
                g[v].push_back({u, count % 2});
            }
        }
        for (int i = 1; i <= m; ++i) {
            int u, v, w;
            std::cin >> u >> v >> w;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        for (int i = 1; i <= n; ++i) {
            if (vis[i]) continue;
            vis[i] = 1;
            val[i] = 0;
            dfs(i);
        }
        if (!flag) std::cout << "NO\n";
        else {
            std::cout << "YES\n";
            for (int u = 1; u <= n; ++u) {
                for (auto [v, w] : e[u]) {
                    if (v <= u) continue;
                    if (w == -1) {
                        w = val[u] ^ val[v];
                    }
                    std::cout << u << ' ' << v << ' ' << w << '\n';
                } 
            }
        }
        
    }

    return 0;
}
// 15 : 09