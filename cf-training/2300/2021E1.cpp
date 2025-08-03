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
int n, m, p;
int s[maxn];
std::vector<std::vector<pii>> e;
int dis[405][405];
int min_dis[405], cur_dis[405], colored[405];
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
        for (int i = 1; i <= n; ++i) colored[i] = 0;
        e.clear();
        e.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            min_dis[i] = 1e9;
        }
        for (int i = 1; i <= p; ++i) {
            std::cin >> s[i];
            colored[s[i]] = 1;
        }


        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dis[i][j] = 1e9;
            }
            dis[i][i] = 0;
        }
        for (int i = 1; i <= m; ++i) {
            int u, v, w;
            std::cin >> u >> v >> w;
            e[u].push_back({v, w});
            e[v].push_back({u, w});
            dis[u][v] = dis[v][u] = w;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                for (int k = 1; k <= n; ++k) {
                    dis[j][k] = std::min(std::max(dis[j][i], dis[i][k]), dis[j][k]);
                }
            }
        }

        for (int t = 1; t <= n; ++t) {
            ll ans = 1e18, source = 0;
            for (int i = 1; i <= n; ++i) {
                ll res = 0;
                for (int j = 1; j <= n; ++j) {
                    cur_dis[j] = min_dis[j];
                }
                for (int j = 1; j <= n; ++j) {
                    cur_dis[j] = std::min(cur_dis[j], dis[i][j]);
                }
                for (int j = 1; j <= n; ++j) {
                    if (colored[j]) res += cur_dis[j];
                }
                if (res < ans) {
                    ans = res;
                    source = i;
                }
            }
            for (int j = 1; j <= n; ++j) {
                min_dis[j] = std::min(min_dis[j], dis[source][j]);
            }
            std::cout << ans << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
// 10 ： 06 - 11 : 25

