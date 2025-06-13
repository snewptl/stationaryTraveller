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
const int maxn = 2e5 + 5;
const ll mod = 998244353;
int n;
std::vector<std::vector<int>> e;
int dp[maxn], need[maxn];
void dfs(int u, int p) {
    int sz = 0, colored = 0, son;
    for (auto v : e[u]) {
        if (v == p) continue;
        ++sz;
        dfs(v, u);
        dp[u] += dp[v];
        if (dp[v]) ++colored, son = v;
    }
    if (colored < sz) {
        dp[u] += sz - colored - 1;
        if (u != 1) need[u] = 1;
        else {
            if (sz - 1 < 2) need[u] = 1; 
        }
    } else {
        if (colored == 1 && need[son]) need[u] = 1;
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
        for (int i = 1; i <= n; ++i) need[i] = 0, dp[i] = 0;
        for (int i = 1; i < n; ++i) {
            int u, v;
            std::cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(1, 0);
        std::cout << dp[1] + need[1] << '\n';
    }

    return 0;
}
