#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <assert.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef std::tuple<int, int, int> tup;
typedef double db;
typedef long double ldb;
const int maxn = 6e5 + 5;
int n, q;
int b[maxn];
int a[maxn];
std::vector<std::vector<int>> e, g;
std::vector<std::vector<int>> original_val, final, seq; 
std::map<pii, int> mp;
int count;
std::vector<tup> operations;
int val[maxn], temp[maxn];
int flag;

int hash(int x, int t) {
    auto it = std::upper_bound(all(seq[x]), t);
    int new_t = *(--it);
    assert(mp.count({x, new_t}));
    return mp[{x, new_t}];
}

namespace tarjan {
    int dfn[maxn], low[maxn], dfncnt, s[maxn], in_stack[maxn], tp;
    int scc[maxn], sc;  // 结点 i 所在 SCC 的编号
    int sz[maxn];       // 强连通 i 的大小
    int in[maxn];

    void clear() {
        dfncnt = 0;
        sc = 0;
        for (int i = 1; i <= count; ++i) {
            dfn[i] = 0;
            sz[i] = 0;
            in[i] = 0;
        }
    }

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
                if (original_val[s[tp]].size()) {
                    if (val[sc]) flag = 1;
                    else val[sc] = original_val[s[tp]][0];
                }
                if (s[tp] <= n) final[sc].push_back(s[tp]);
                sz[sc]++;
                in_stack[s[tp]] = 0;
            } while (s[tp--] != u);
        }
    }

    void rebuild() {
        for (int i = 1; i <= count; ++i) {
            for (auto v : e[i]) {
                if (scc[i] != scc[v]) {
                    g[scc[i]].push_back(scc[v]);
                    in[scc[v]] += 1;
                }
            }
        }
    }
};

void solve() {
    tarjan::clear();
    for (int i = 1; i <= count; ++i) {
        if (!tarjan::dfn[i]) tarjan::tarjan(i);
    }
    tarjan::rebuild();
    if (flag) {
        std::cout << "-1\n";
        return;
    }
    int N = tarjan::sc;
    std::queue<int> q;
    for (int i = 1; i <= N; ++i) {
        if (tarjan::in[i] == 0) {
            q.push(i);
            if (!val[i]) val[i] = 1;
        }
    }
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : g[u]) {
            temp[v] = std::max(temp[v], val[u]);
            tarjan::in[v]--;
            if (tarjan::in[v] == 0) {
                if (val[v]) {
                    if (val[v] < temp[v]) {
                        std::cout << "-1\n";
                        return;
                    }
                } else {
                    val[v] = temp[v];
                }
                q.push(v);
            }
        }
        for (auto it : final[u]) a[it] = val[u];
    }

    for (int i = 1; i <= N; ++i) {
        int mn = 1e9 + 1;
        for (auto v : g[i]) {
            mn = std::min(mn, val[v]);
        }
        if (mn != 1e9 + 1 && mn != val[i]) {
            std::cout << "-1\n";
            return;
        }
    }
    for (int i = 1; i <= n; ++i) std::cout << a[i] << ' ';
    std::cout << '\n';
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
        std::cin >> n >> q;
        flag = 0;
        g.clear();
        mp.clear();
        count = 0;
        seq.clear();
        e.clear();
        original_val.clear();
        final.clear();
        e.resize(n + q + 1);
        seq.resize(n + 1);
        original_val.resize(n + q + 1);
        final.resize(n + q + 1);
        g.resize(n + q + 1);
        operations.clear();
        for (int i = 1; i <= n; ++i) {
            std::cin >> b[i];
            mp[{i, 0}] = ++count;
            a[i] = 0;
            seq[i].push_back(0);
        }

        for (int i = 1; i <= q; ++i) {
            int x, y, z;
            std::cin >> x >> y >> z;
            if (!mp.count({z, i})) mp[{z, i}] = ++count;
            seq[z].push_back(i);
            operations.push_back({x, y, z});
        }

        for (int i = 1; i <= n + q; ++i) {
            val[i] = 0;
            temp[i] = 0;
        }

        for (int i = 1; i <= q; ++i) {
            auto [x, y, z] = operations[i - 1];
            int new_x = hash(x, i - 1);
            int new_y = hash(y, i - 1);
            int new_z = hash(z, i);
            if (new_z != new_x) e[new_z].push_back(new_x);
            if (new_z != new_y) e[new_z].push_back(new_y);
        }

        for (int i = 1; i <= n; ++i) {
            int last = seq[i].back();
            int idx = mp[{i, last}];
            original_val[idx].push_back(b[i]);
        }

        solve();
    }

    return 0;
}

