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
const int maxn = 3e3 + 5;
const ll mod = 998244353;
int n;
std::vector<std::vector<int>> e;
int dis[maxn][maxn], sz[maxn][maxn];
std::vector<std::vector<pii>> vec;
ll dp[maxn][maxn];
void dfs(int rt, int u, int p) {
    sz[rt][u] = 1;
    for (auto v : e[u]) {
        if (v == p) continue;
        dis[rt][v] = dis[rt][u] + 1;
        dfs(rt, v, u);
        sz[rt][u] += sz[rt][v];
    }
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    e.resize(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v;
        std::cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        dfs(i, i, 0);
    }
    vec.resize(n);
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            vec[dis[i][j]].push_back({i, j});
        }
    }
    for (int i = n - 1; i >= 1; --i) {
        for (auto [x, y] : vec[i]) {
            if (sz[x][y] == 1 && sz[y][x] == 1) dp[x][y] = dp[y][x] = 1;
            for (auto v : e[x]) {
                if (dis[v][y] == dis[x][y] - 1) {
                    ll val = 1ll * sz[v][y] * sz[y][v] + dp[x][y];
                    dp[v][y] = dp[y][v] = std::max(dp[v][y], val);
                }
            }
            for (auto v : e[y]) {
                if (dis[v][x] == dis[x][y] - 1) {
                    ll val = 1ll * sz[v][x] * sz[x][v] + dp[x][y];
                    dp[v][x] = dp[x][v] = std::max(dp[v][x], val);
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (dis[i][j] == 1) {
               ans = std::max(ans, dp[i][j]); 
            }
        }
    }
    std::cout << ans << '\n';

    return 0;
}
// 18 : 47 - 19 : 20