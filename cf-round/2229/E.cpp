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
ll dp[maxn];
std::vector<std::vector<int>> e;
int max[maxn];
int n;
void dfs(int u, int p) {
    std::vector<pii> vec;
    for (auto v : e[u]) {
        if (v == p) continue;
        dfs(v, u);
        vec.push_back({max[v], v});
    }
    std::sort(all(vec));
    ll mul = 0;
    int mx = max[u];
    for (auto [_, v] : vec) {
        mx = std::max(mx, max[v]);
        mul += 1;
        mul *= dp[v];
        mul %= mod;
    }
    if (mul == 0) mul = 1;
    dp[u] = mul;
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
        std::cin >> n;
        e.clear();
        e.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            max[i] = i;
        }
        for (int i = 1; i < n; ++i) {
            int u, v;
            std::cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        int root = 1;
        for (int i = 1; i <= n; ++i) {
            if (e[i].size() != 1) root = i;
        }
        dfs(root, 0);
        std::cout << dp[root] << '\n';
    }

    return 0;
}
