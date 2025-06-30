#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <assert.h>
#include <cmath>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 10;
const ll mod = 998244353;
int n, m;
std::vector<std::vector<int>> e;
int color[maxn];
int dis[4][maxn], fa[4][maxn];
int vis[maxn];
void bfs(int id, int u) {
    for (int i = 1; i <= n + 4; ++i) vis[i] = 0;
    std::queue<int> q;
    q.push(u);
    vis[u] = 1;
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        for (auto v : e[p]) {
            if (vis[v]) continue;
            dis[id][v] = dis[id][p] + 1;
            vis[v] = 1;
            fa[id][v] = p;
            q.push(v);
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

    std::cin >> n >> m;
    e.resize(n + 4);
    for (int i = 1; i <= 3; ++i) {
        int sz;
        std::cin >> sz;
        for (int j = 1; j <= sz; ++j) {
            int u;
            std::cin >> u;
            color[u] = i;
        }
    }
    for (int i = 1; i <= m; ++i) {
        int u, v;
        std::cin >> u >> v;
        if (color[u]) u = color[u] + n;
        if (color[v]) v = color[v] + n;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= 3; ++i) {
        bfs(i, i + n);
    }
    int ans = n + 1;
    std::vector<int> res;
    for (int i = 1; i <= 3; ++i) {
        int u = n + (i + 1 - 1) % 3 + 1;
        int v = n + (i + 2 - 1) % 3 + 1;
        if (ans > dis[i][u] + dis[i][v] - 2) {
            ans = std::min(ans, dis[i][u] + dis[i][v] - 2);
            res.clear();
            int cur = u;
            while (fa[i][cur] != i + n) {
                cur = fa[i][cur];
                res.push_back(cur);
            }
            cur = v;
            while (fa[i][cur] != i + n) {
                cur = fa[i][cur];
                res.push_back(cur);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (color[i]) continue;
        int temp = 0;
        for (int j = 1; j <= 3; ++j) {
            temp += dis[j][i];
        }
        if (ans > temp - 2) {
            ans = temp - 2;
            res.clear();
            res.push_back(i);
            for (int j = 1; j <= 3; ++j) {
                int cur = i;
                while (fa[j][cur] != j + n) {
                    cur = fa[j][cur];
                    res.push_back(cur);
                }
            }
        }
    }
    assert(ans == res.size());
    std::cout << ans << '\n';
    for (auto it : res) std::cout << it << '\n';

    return 0;
}
