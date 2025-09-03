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
const ll mod = 998244353;
int n, m, V;
std::vector<std::vector<int>> e;
int a[maxn];
namespace tarjan {
    int dfn[maxn], low[maxn], dfncnt, s[maxn], in_stack[maxn], tp;
    int scc[maxn], sc;
    int sz[maxn];
    int col[maxn];

    void tarjan(int u, int p) {
        low[u] = dfn[u] = ++dfncnt, s[++tp] = u, in_stack[u] = 1;
        for (auto v : e[u]) {
            if (v == p) continue;
            if (!dfn[v]) {
                tarjan(v, u);
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

    ll count() {
        ll ans = 1;
        std::vector<std::vector<int>> vec;
        vec.resize(sc + 1);
        for (int i = 1; i <= n; ++i) {
            col[i] = 0;
            vec[scc[i]].push_back(i);
        }
        for (int i = 1; i <= sc; ++i) {
            int flag = 1;
            std::queue<int> q;
            q.push(vec[i][0]);
            col[vec[i][0]] = 2;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (auto v : e[u]) {
                    if (scc[v] != scc[u]) continue;
                    if (col[v]) {
                        if ((col[v] ^ col[u]) != 1) flag = 0;
                    } else {
                        col[v] = col[u] ^ 1;
                        q.push(v);
                    }
                }
            }
            if (sz[i] == 1) flag = 1;
            int last = -1;
            for (auto u : vec[i]) {
                if (a[u] == -1) continue;
                if (last == -1) {
                    last = a[u];
                } else if (last != a[u]) ans = 0;
            }
            if (flag) {
                if (last == -1) ans *= V, ans %= mod;
            } else {
                if (last != -1 && last != 0) ans = 0;
            }
        }
        return ans;
    }
};

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
        
        std::cin >> n >> m >> V;
        e.clear();
        e.resize(n + 1);
        tarjan::clear();
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        for (int i = 1; i <= m; ++i) {
            int u, v;
            std::cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        tarjan::tarjan(1, 0);
        std::cout << tarjan::count() << '\n';
    }

    return 0;
}
