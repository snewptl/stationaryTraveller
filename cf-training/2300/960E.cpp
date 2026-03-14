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
const ll mod = 1e9 + 7;
int n;
ll val[maxn];
pll dp[maxn][2];
std::vector<std::vector<int>> e;
ll ans;
void merge(pll & x, pll y) {
    x.first += y.first, x.first = (x.first + mod) % mod;
    x.second += y.second, x.second = (x.second + mod) % mod;
}
void del(pll & x, pll y) {
    x.first -= y.first, x.first = (x.first + mod) % mod;
    x.second -= y.second, x.second = (x.second + mod) % mod;
}
void dfs(int u, int p) {
    for (auto v : e[u]) {
        if (v == p) continue;
        dfs(v, u);
        merge(dp[u][0], dp[v][1]);
        merge(dp[u][1], dp[v][0]);
    }
    merge(dp[u][0], {1ll, val[u]});
}
void cr(int u, int p) {
    dp[u][0] = dp[u][1] = {0, 0};
    dp[u][0] = {1, val[u]};
    ans += val[u];
    ans = (ans % mod + mod) % mod;
    for (auto v : e[u]) {
        ans += (dp[u][0].first * dp[v][1].first - dp[u][1].first * dp[v][0].first) % mod * val[u] * 2 % mod; 
        ans = (ans % mod + mod) % mod;
        merge(dp[u][0], dp[v][1]);
        merge(dp[u][1], dp[v][0]);
    }
    for (auto v : e[u]) {
        if (v == p) continue;
        pll temp[2];
        temp[0] = dp[u][0];
        temp[1] = dp[u][1];
        del(dp[u][0], dp[v][1]);
        del(dp[u][1], dp[v][0]);
        merge(dp[v][0], dp[u][1]);
        merge(dp[v][1], dp[u][0]);
        cr(v, u);
        dp[u][0] = temp[0];
        dp[u][1] = temp[1];
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
    for (int i = 1; i <= n; ++i) {
        std::cin >> val[i];
    }
    e.resize(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v;
        std::cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    cr(1, 0);
    std::cout << ans << '\n';

    return 0;
}
// 17 : 43 - 