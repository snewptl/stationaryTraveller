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
const int maxn = 4e5 + 5;
const ll mod = 998244353;
int n, m, p;
int vis[maxn], son[maxn],  sz[maxn];
int used[maxn];
int node_count;
ll dp[maxn], val[maxn];
std::vector<std::vector<int>> g;
std::vector<std::tuple<int, int, int>> e;
int fa[maxn], pa[maxn];
ll sum;
std::vector<ll> vec;
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void dfs(int u) {
    for (auto v : g[u]) {
        pa[v] = u;
        dfs(v);
        sz[u] += sz[v];
        if (vis[v]) vis[u] = 1;
        ll new_val = dp[v] + sz[v] * (val[u] - val[v]);
        sum += sz[v] * (val[u] - val[v]);
        if (dp[u] <= new_val) {
            dp[u] = new_val;
            son[u] = v;
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
        std::cin >> n >> m >> p;
        e.clear();
        g.clear();
        g.resize(n * 2);
        vec.clear();
        sum = 0;
        for (int i = 1; i <= n * 2; ++i) {
            vis[i] = 0;
            fa[i] = i;
            son[i] = 0;
            val[i] = 0;
            used[i] = 0;
            sz[i] = 0;
            dp[i] = 0;
        }
        node_count = n;
        for (int i = 1; i <= p; ++i) {
            int x;
            std::cin >> x;
            vis[x] = 1;
            sz[x] = 1;
        }
        for (int i = 1; i <= m; ++i) {
            int u, v, w;
            std::cin >> u >> v >> w;
            e.push_back({w, u, v});
        }
        std::sort(all(e));
        for (auto [w, u, v] : e) {
            if (find(u) == find(v)) continue;
            ++node_count;
            val[node_count] = w;
            g[node_count].push_back(find(u));
            g[node_count].push_back(find(v));
            fa[find(u)] = node_count;
            fa[find(v)] = node_count; 
        }
        pa[2 * n - 1] = 2 * n - 1;
        dfs(2 * n - 1);
        for (int i = n * 2 - 1; i >= 1; --i) {
            if (used[i] || !vis[i]) continue;
            int cur = i;
            while (cur != 0) {
                used[cur] = 1;
                cur = son[cur];
            }
            vec.push_back((val[pa[i]] - val[i]) * sz[i] + dp[i]);
        }
        std::sort(all(vec));
        for (int i = 1; i <= n; ++i) {
            if (!vec.empty()) {
                sum -= vec.back();
                vec.pop_back();
            }
            std::cout << sum << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}

