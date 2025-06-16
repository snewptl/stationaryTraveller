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
int n, m;
std::vector<std::vector<pii>> e;
std::vector<std::vector<int>> g;
int dir[maxn];
int in[maxn], vis[maxn], in_stack[maxn], a[maxn];
int solvable = 1;
int dfn_num = 0;
void dfs(int u) {
    for (auto [v, w] : e[u]) {
        if (dir[v]) {
            if (dir[v] == dir[u]) solvable = 0;
        } else {
            dir[v] = 3 - dir[u];
            dfs(v);
        }
    }
}
void find_circle() {
    std::queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (!in[i]) {
            q.push(i);
            a[i] = ++dfn_num;
        }
    }
    while(!q.empty()) {
        int p = q.front(); q.pop();
        for (auto v : g[p]) {
            --in[v];
            if (!in[v]) {
                a[v] = ++dfn_num;
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!a[i]) solvable = 0;
    }
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    e.clear();
    e.resize(n + 1);
    for (int i = 1; i <= m; ++i) {
        int w, u, v;
        std::cin >> w >> u >> v;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    for (int i = 1; i <= n; ++i) {
        if (!dir[i]) {
            dir[i] = 1;
            dfs(i);
        }
    }

    g.resize(n + 1);
    for (int u = 1; u <= n; ++u) {
        for (auto [v, w] : e[u]) {
            if (v > u) continue;
            if (dir[u] == 1) {
                if (w == 1) {
                    g[v].push_back(u);
                } else {
                    g[u].push_back(v);
                }
            } else {
                if (w == 1) {
                    g[u].push_back(v);
                } else {
                    g[v].push_back(u);
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (auto it : g[i]) {
            ++in[it];
        }
    }
    find_circle();
    if (solvable) {
        std::cout << "YES\n";
        for (int i = 1; i <= n; ++i) {
            if (dir[i] == 1) std::cout << "R ";
            else std::cout << "L ";
            std::cout << a[i] << '\n';
        }
    } else std::cout << "NO\n";
    return 0;
}

// 15 : 35