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
const int maxn = 2e6 + 5;
const ll mod = 998244353;
int n, m;
std::pair<ll, pii> e[maxn];
std::vector<std::vector<int>> g;
int fa[maxn];
int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int count[maxn], deg[maxn];
int val[maxn];
ll ans;
int new_node;
void dfs(int u) {
    int sum = 0;
    for (auto v : g[u]) {
        val[v] = std::min(val[u], val[v]);
        dfs(v);
        sum += count[v];
    }
    if (sum == 1) {
        count[u] = 1;
    } else if (sum == 2) {
        ans += val[u];
        
    }

}
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
        for (int i = 1; i <= n; ++i) {
            deg[i] = 0;
        }
        for (int i = 1; i <= m + n; ++i) {
            fa[i] = i;
            val[i] = 0;
            count[i] = 0;
        }
        ans = 0;
        new_node = n;
        g.clear();
        g.resize(m + n + 1);
        for (int i = 1; i <= m; ++i) {
            int u, v;
            ll w;
            std::cin >> u >> v >> w;
            ans += w;
            deg[u] += 1;
            deg[v] += 1;
            e[i] = {w, {u, v}};
        }
        for (int i = 1;i <= n; ++i) {
            count[i] = deg[i] % 2;
        }
        for (int i = 1; i <= m; ++i) {
            auto [w, p] = e[i];
            auto [u, v] = p;
            if (find(u) != find(v)) {
                ++new_node;
                g[new_node].push_back(find(u));
                g[new_node].push_back(find(v));
                fa[find(u)] = new_node;
                fa[find(v)] = new_node;
                val[new_node] = w;
            } else {
                ++new_node;
                g[new_node].push_back(find(u));
                fa[find(u)] = new_node;
                val[new_node] = w;
            }
        }
        dfs(m + n);
        std::cout << ans << '\n';
    }

    return 0;
}