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
int n, m;
std::vector<std::vector<pii>> e[2];
pii edge[maxn];
int dsu[maxn];
int find(int x) {
    return find(x) == x ? x : dsu[x] = find(dsu[x]);
}
namespace tarjan {
    int dfn[maxn], low[maxn], dfncnt, s[maxn], in_stack[maxn], tp;
    int scc[maxn], sc; 
    int sz[maxn]; 

    void tarjan(int u, int p, std::vector<std::vector<pii>>& e) { // bi - direct
        low[u] = dfn[u] = ++dfncnt, s[++tp] = u, in_stack[u] = 1;
        for (auto [v, _] : e[u]) {
            if (v == p) continue;
            if (!dfn[v]) {
                tarjan(v, u, e);
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

    void solve() {
        std::vector<std::vector<int>> vec;
        vec.resize(sc + 1);
        for (int i = 1; i <= n; ++i) {
            vec[scc[i]].push_back(i);
        }
        for (int i = 1; i <= sc; ++i) {
            std::set<int> s;
            for (auto u : vec[i]) {
                for (auto [v, index] : e[1][u]) {
                    if (scc[v] != scc[u]) continue;
                    s.insert(edge[index].first);
                    s.insert(edge[index].second);
                }
            }
            if (s.size() )
        }
    }

    void clear() {
        for (int i = 1; i <= sc; ++i) {
            sz[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            dfn[i] = low[i] = 0;
        }
        sc = 0;
        dfncnt = 0;
    }
};
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
        std::cin >> n >> m;
        for (int i = 0; i < 2; ++i) {
            e[i].clear();
            e[i].resize(n + 1);
        }
        for (int i = 1; i <= m; ++i) {
            int u1, v1, u2, v2;
            for (int j = 0; j < 2; ++j) {
                int u, v;
                std::cin >> u >> v;
                if (j == 0) edge[i] = {u, v};
                e[j][u].push_back({v, i});
                e[j][v].push_back({u, i});
            }
        }
        tarjan::clear();
        tarjan::tarjan(1, 0, e[1]);
        tarjan::solve();
    }

    return 0;
}
