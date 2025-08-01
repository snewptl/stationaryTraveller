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
int n, m, q;
int dp[405][405][405], dis[405], in_queue[405];
std::vector<int> weight;
std::vector<std::vector<pii>> e;
std::vector<std::vector<int>> g;
int fa[maxn];
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
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
        std::cin >> n >> m >> q;
        e.clear();
        e.resize(n + 1);
        weight.clear();
        for (int i = 1; i <= m; ++i) {
            int u, v, w;
            std::cin >> u >> v >> w;
            e[u].push_back({v, w});
            e[v].push_back({u, w});
            weight.push_back(w);
        }
        std::sort(all(weight));
        weight.resize(std::unique(all(weight)) - weight.begin());
        std::reverse(all(weight));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                for (int k = 0; k <= n; ++k) {
                    dp[i][j][k] = 1e9;
                }
            }   
            for (auto cur_weight : weight) {
                for (int j = 1; j <= n; ++j) {
                    dis[j] = 1e9;
                    fa[j] = j;
                    in_queue[j] = 0;
                }
                for (int j = 1; j <= n; ++j) {
                    for (auto [v, w] : e[j]) {
                        if (w <= cur_weight) {
                            fa[find(v)] = find(j);
                        } 
                    }
                }
                g.clear();
                g.resize(n + 1);
                for (int j = 1; j <= n; ++j) {
                    for (auto [v, w] : e[j]) {
                        if (w > cur_weight) {
                            g[find(j)].push_back(find(v));
                        }
                    }
                }
                std::queue<int> q;
                q.push(find(i));
                dis[find(i)] = 0;
                in_queue[find(i)] = 1;
                while (!q.empty()) {
                    auto u = q.front(); q.pop();
                    for (auto v : g[u]) {
                        if (in_queue[v]) continue;
                        if (dis[v] > dis[u] + 1) {
                            dis[v] = dis[u] + 1;
                            q.push(v);
                            in_queue[v] = 1;
                        }
                    }
                }
                for (int j = 1; j <= n; ++j) {
                    dp[i][j][dis[find(j)] + 1] = cur_weight;
                }
            }
            for (int j = 1; j <= n; ++j) {
                for (int k = 2; k <= n; ++k) {
                    dp[i][j][k] = std::min(dp[i][j][k], dp[i][j][k - 1]);
                }
            }
        }
        for (int i = 1; i <= q; ++i) {
            int a, b, k;
            std::cin >> a >> b >> k;
            std::cout << dp[a][b][k] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
// 10 : 55 - 11 : 30
// 14 : 30 - 15 : 20