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
const int maxn = 3e5 + 5;
const ll mod = 998244353;
int n, m;
std::vector<std::vector<int>> e;
int vis[maxn];
void dfs(int u) {
    vis[u] = 1;
    for (int v : e[u]) {
        if (vis[v]) continue;
        dfs(v);
    }
}
void solve() {
    for (int i = 1; i <= n; ++i) {
        if (e[i].empty()) {
            std::cout << "Brain Melt\n";
            return;
        }
    }
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            count += 1;
            if (count > 1) {
                std::cout << "Many\n";
                return;
            }
            dfs(i);
        }
    }
    int deg = 0;
    for (int i = 1; i <= n; ++i) {
        if (e[i].size() == 1) deg += 1;
    }
    if (deg != n - 1) std::cout << "Many\n";
    else std::cout << "2\n";

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
        for (int i = 1; i <= m; ++i) {
            int u, v;
            std::cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        for (int i = 1; i <= n; ++i) {
            vis[i] = 0;
        }
        solve();
    }

    return 0;
}
