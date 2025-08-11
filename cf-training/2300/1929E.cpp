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
std::vector<std::vector<std::tuple<int, int, int>>> path;
std::vector<pii> rank;
int n, k;
int fa[maxn][20], dep[maxn];
int vis[21];
int ans;
void dfs(int u, int p) {
    fa[u][0] = p; 
    for (auto v : e[u]) {
        if (v == p) continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}
int lca(int a, int b) {
    if (dep[a] < dep[b]) std::swap(a, b);
    for (int j = 19; j >= 0; --j) {
        if (dep[fa[a][j]] > dep[b]) {
            a = fa[a][j];
        }
    }
    if (dep[a] > dep[b]) a = fa[a][0];
    for (int j = 19; j >= 0; --j) {
        if (fa[a][j] != fa[b][j]) {
            a = fa[a][j];
            b = fa[b][j];
        }
    }
    if (a != b) a = fa[a][0];
    return a;
}
bool check(int top, int a, int cur) {
    int i = rank[cur].second;
    for (auto [new_top, b, _] : path[i]) {
        if (lca(new_top, top) == new_top && lca(b, a) == a) return true;
    }
    return false;
}
void solve(int cur, int count) {
    if (cur == k) {
        ans = std::min(ans, count);
        return;
    }
    int i = rank[cur].second;
    if (vis[cur]) {
        solve(cur + 1, count);
        return;
    }
    for (auto [top, bot, a] : path[i]) {
        std::vector<int> changed;
        changed.push_back(cur);
        vis[cur] = 1;
        for (int j = cur + 1; j < k; ++j) {
            if (check(top, a, j) && !vis[j]) {
                changed.push_back(j);
                vis[j] = 1;
            }
        }
        solve(cur + 1, count + 1);
        for (auto it : changed) {
            vis[it] = 0;
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
        std::cin >> n;
        e.clear();
        e.resize(n + 1);

        for (int i = 1; i < n; ++i) {
            int u, v;
            std::cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dep[1] = 1;
        dfs(1, 0);
        for (int i = 1; i < 20; ++i) {
            for (int j = 1; j <= n; ++j) {
                fa[j][i] = fa[fa[j][i - 1]][i - 1];
            }
        }
        std::cin >> k;
        path.clear();
        path.resize(k + 1);
        rank.clear();
        ans = k;
        for (int i = 1; i <= k; ++i) {
            int a, b;
            std::cin >> a >> b;
            int top = lca(a, b);     
            int new_a = a, new_b = b;   
            for (int j = 19; j >= 0; --j) {
                if (dep[fa[new_a][j]] > dep[top]) {
                    new_a = fa[new_a][j];
                }
                if (dep[fa[new_b][j]] > dep[top]) {
                    new_b = fa[new_b][j];
                }                
            }
            if (top != new_a) path[i].push_back({top, a, new_a});
            if (top != new_b) path[i].push_back({top, b, new_b});
            rank.push_back({dep[top], i});
        }
        std::sort(all(rank));
        std::reverse(all(rank));
        solve(0, 0);
        std::cout << ans << '\n';
    }

    return 0;
}
// 9 : 55 - 11 : 00