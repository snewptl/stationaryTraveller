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
std::vector<std::vector<pii>> e, g;
int in[maxn], sc;
namespace tarjan {
    int dfn[maxn], low[maxn], dfncnt, s[maxn], in_stack[maxn], tp;
    int scc[maxn];  // 结点 i 所在 SCC 的编号
    int sz[maxn];       // 强连通 i 的大小

    void tarjan(int u, int x) {
        low[u] = dfn[u] = ++dfncnt, s[++tp] = u, in_stack[u] = 1;
        for (auto [w, v] : e[u]) {
            if (!dfn[v]) {
                tarjan(v, x);
                low[u] = std::min(low[u], low[v]);
            } else if (in_stack[v]) {
                low[u] = std::min(low[u], dfn[v]);
            }
        }
        for (auto [w, v] : g[u]) {
            if (w > x) break;
            if (!dfn[v]) {
                tarjan(v, x);
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
                in_stack[s[tp]] = 0;
            } while (s[tp--] != u);
        }
    }

    void init(int x) {
        for (int i = 1; i <= n; ++i) {
            if (!dfn[i]) tarjan(i, x);
        }
        for (int i = 1; i <= n; ++i) {
            for (auto [w, v] : e[i]) {
                if (scc[i] != scc[v]) in[scc[v]] += 1;
            }
        }
    }

    void clear() {
        for (int i = 1; i <= sc; ++i) sz[i] = 0, in[i] = 0;
        for (int i = 1; i <= n; ++i) {
            dfn[i] = low[i] = 0;
        }
        sc = 0;
        dfncnt = 0;
    }
};

bool check(int x) {
    tarjan::clear();
    tarjan::init(x);
    int count =  0;
    for (int i = 1; i <= sc; ++i) if (in[i] == 0) ++count;
    return count == 1;
}
void solve() {
    int l = 0, r = 1e9, ans = 2e9;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    std::cout << (ans == 2e9 ? -1 : ans) << '\n';
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
        g.clear();
        g.resize(n + 1);
        e.clear();
        e.resize(n + 1);
        for (int i = 1; i <= m; ++i) {
            int u, v, w;
            std::cin >> u >> v >> w;
            e[u].push_back({w, v});
            g[v].push_back({w, u});
        }
        for (int i = 1; i <= n; ++i) {
            std::sort(all(g[i]));
        }
        solve();
    }

    return 0;
}

// 15 : 00