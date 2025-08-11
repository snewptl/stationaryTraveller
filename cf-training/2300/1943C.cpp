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
int n;
std::vector<std::vector<int>> e;
int dep[maxn];
int mn_dep, rt;
void dfs(int u, int p) {
    dep[u] = 1;
    for (auto v : e[u]) {
        if (v == p) continue;
        dfs(v, u);
        dep[u] = std::max(dep[v] + 1, dep[u]);
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
        mn_dep = 1e9;
        for (int i = 1; i < n; ++i) {
            int u, v;
            std::cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dep[j] = 0;
            }
            dfs(i, 0);
            if (dep[i] < mn_dep) {
                mn_dep = dep[i];
                rt = i;
            }
        }
        std::cout << mn_dep << '\n';
        for (int i = 1; i <= mn_dep; ++i) {
            std::cout << rt << ' ' << i - 1 << '\n';
        }
    }

    return 0;
}
// 17 : 43 - 18 : 00 