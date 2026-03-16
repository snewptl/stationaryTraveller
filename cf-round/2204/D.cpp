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
int n, m;
std::vector<std::vector<int>> e;
int vis[maxn], used[maxn];
int check(int root, int sgn) {
    int flag = 1;
    std::queue<int> q;
    vis[root] = sgn;
    q.push(root);
    std::vector<int> vec;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        vec.push_back(u);
        used[u] = 1;
        int nsgn = 3 - vis[u];
        for (auto v : e[u]) {
            if (!vis[v]) {
                vis[v] = nsgn;
                q.push(v);
            } else if (vis[v] != nsgn) {
                flag = 0;
            }
        }
    }
    if (!flag) return 0;
    int res = 0;
    for (auto u : vec) {
        if (vis[u] == 1) res += 1;
        vis[u] = 0;
    }
    return res;
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
        e.clear();
        e.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            vis[i] = 0;
            used[i] = 0;
        }
        for (int i = 1; i <= m; ++i) {
            int u, v;
            std::cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (used[i]) continue;
            ans += std::max(check(i, 1), check(i, 2));
            // std::cout << " #$"<< i << ' ' <<  std::max(check(i, 1), check(i, 2));
        }
        std::cout << ans << '\n';
    }

    return 0;
}
