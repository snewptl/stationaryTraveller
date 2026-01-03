#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <unordered_map>
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
ll a[maxn];
std::vector<std::vector<int>> e;
std::vector<std::map<ll, ll>> dp;
struct edge {
    int u, v;
    ll w;
    bool operator<(const edge& new_edge) const {
        w < new_edge.w;
    }
};
std::vector<edge> edges;
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
        dp.clear();
        dp.resize(n + 1);
        edges.clear();
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        ll ans = 0;
        for (int i = 1; i <= m; ++i) {
            int u, v;
            std::cin >> u >> v;
            e[u].push_back(v);
            dp[v][a[u]] += 1;
            if (a[v] - a[u] > 0) {
                edges.push_back({u, v, a[v] - a[u]});
            }
        }
        std::sort(all(edges));
        for (auto [u, v, w] : edges) {
            if (dp[u].count(w)) {
                dp[v][a[u]] += dp[u][w];
                dp[v][a[u]] %= mod;
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (auto [_, val] : dp[i]) {
                ans += val;
                ans %= mod;
            }
        }

        std::cout << ans << "\n";
        
    }

    return 0;
}
