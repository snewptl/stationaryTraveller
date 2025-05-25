#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
const int inf = 1e9 + 5;
int n, a[maxn], dp[maxn];
std::vector<int> e[maxn];
void dfs(int u, int p) {
    dp[u] = inf;
    for (auto v : e[u]) {
        if (v == p) continue;
        dfs(v, u);
        dp[u] = std::min(dp[u], dp[v]);
    }
    if (u == 1) {
        std::cout << (dp[u] == inf ? a[u] : dp[u] + a[u]) << '\n';
        return;
    }
    if (dp[u] == inf) {
        dp[u] = a[u];
    } else if (dp[u] > a[u]) {
        dp[u] = (dp[u] + a[u]) / 2;
    }
}
int main() {
    #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        for (int i = 2; i <= n; ++i) {
            int p; std::cin >> p;
            e[p].push_back(i);
            e[i].push_back(p);
        }
        dfs(1, 0);
        for (int i = 1; i <= n; ++i) {
            e[i].clear();
        }
    }

    return 0;
}
