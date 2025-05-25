#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
int new_n;
std::vector<std::vector<int>> g;
ll val[maxn], sum[maxn];
int in[maxn], dis[maxn];
int sz[maxn];       
int a[maxn];
namespace Tarjan {
    int n, m;
    int dfn[maxn], low[maxn], dfncnt, s[maxn], in_stack[maxn], tp;
    int scc[maxn], sc;  
    std::vector<int> e[maxn];

    void tarjan(int u) {
        low[u] = dfn[u] = ++dfncnt, s[++tp] = u, in_stack[u] = 1;
        for (auto v : e[u]) {
            if (!dfn[v]) {
                tarjan(v);
                low[u] = std::min(low[u], low[v]);
            } else if (in_stack[v]) {
                low[u] = std::min(low[u], dfn[v]);
            }
        }
        if (dfn[u] == low[u]) {
            ++sc;
            do {
                scc[s[tp]] = sc;
                sz[sc]++;
                val[sc] += a[s[tp]];
                in_stack[s[tp]] = 0;
            } while (s[tp--] != u);
        }
    }

    void rebuild() {
        g.resize(sc + 1);
        for (int i = 1; i <= n; ++i) {
            for (auto v : e[i]) {
                if (scc[i] == scc[v]) continue;
                g[scc[i]].push_back(scc[v]);
            }
        }
        for (int i = 1; i <= sc; ++i) {
            sort(all(g[i]));
            g[i].resize(std::unique(all(g[i])) - g[i].begin());
            for (auto v : g[i]) {
                ++in[v];
            }
        }
    }

    void clear() {
        g.clear();
        for (int i = 1; i <= sc; ++i) {
            sz[i] = 0;
            val[i] = 0;
            sum[i] = 0;
            in[i] = 0;
            dis[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            dfn[i] = low[i] = 0;
            e[i].clear();
            dfncnt = 0;
            tp = 0;
            sc = 0;
        }
    }
};
void bfs() {
    std::queue<int> q;
    for (int i = 1; i <= new_n; ++i) {
        if (in[i] == 0) {
            q.push(i);
            dis[i] = sz[i];
            sum[i] = val[i];
        }
    }
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        for (auto v : g[u]) {
            --in[v];
            if (dis[v] < dis[u] + sz[v]) {
                dis[v] = dis[u] + sz[v];
                sum[v] = sum[u] + val[v];
            } else if (dis[v] == dis[u] + sz[v]) {
                sum[v] = std::min(sum[v], sum[u] + val[v]);
            }
            if (!in[v]) q.push(v);
        }
    }
    int len = 0;
    ll ans = 0;
    for (int i = 1; i <= new_n; ++i) {
        if (len < dis[i]) {
            len = dis[i];
            ans = sum[i];
        } else if (len == dis[i]) {
            ans = std::min(ans, sum[i]);
        }
    }
    std::cout << len << " " << ans << '\n';
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
        std::cin >> Tarjan::n >> Tarjan::m;
        for (int i = 1; i <= Tarjan::n; ++i) {
            std::cin >> a[i];
        }
        for (int i = 1; i <= Tarjan::m; ++i) {
            int u, v;
            std::cin >> u >> v;
            Tarjan::e[u].push_back(v);
        }
        for (int i = 1; i <= Tarjan::n; ++i) {
            if (!Tarjan::dfn[i]) Tarjan::tarjan(i);
        }
        Tarjan::rebuild();
        new_n = Tarjan::sc;
        bfs();
        Tarjan::clear();
    }

    return 0;
}
