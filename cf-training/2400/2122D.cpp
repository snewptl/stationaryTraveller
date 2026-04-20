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
void bfs() {
    std::vector<std::vector<int>> dis;
    dis.clear();
    dis.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        dis[i].resize(2, 1e9);
    }
    dis[1][0] = 0;
    for (int t = 0; t < 3 * n; ++t) {
        for (int u = 1; u <= n; ++u) {
            int v = e[u][t % e[u].size()].second;
            dis[v][1] = std::min(dis[v][1], dis[u][0]);
            dis[u][1] = std::min(dis[u][1], dis[u][0] + 1);
        }
        for (int u = 1; u <= n; ++u) {
            std::swap(dis[u][0], dis[u][1]);
            dis[u][1] = 1e9;
        }
        if (dis[n][0] != 1e9) {
            std::cout << t + 1 << ' ' << dis[n][0] << '\n';
            return;
        }   
    }
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> m;
        e.clear();
        e.resize(n + 1);
        for (int i = 1; i <= m; ++i) {
            int u, v;
            std::cin >> u >> v;
            e[u].push_back({i, v});
            e[v].push_back({i, u});
        }
        for (int i = 1; i <= n; ++i) {
            sort(all(e[i]));
        }
        bfs();
    }

    return 0;
}