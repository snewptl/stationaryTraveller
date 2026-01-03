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
std::vector<std::unordered_map<ll, ll>> dp[2];
bool flag;
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
        for (int i = 0; i < 2; ++i) {
            dp[i].clear();
            dp[i].resize(n + 1);
        }
        flag = 0;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        ll ans = 0;
        for (int i = 1; i <= m; ++i) {
            int u, v;
            std::cin >> u >> v;
            e[u].push_back(v);
            dp[0][v][a[u]] += 1;
            flag = 1;
        }
        while (flag) {
            flag = 0;
            dp[1].clear();
            dp[1].resize(n + 1);
            for (int u = 1; u <= n; ++u) {
                for (auto [_, val] : dp[0][u]) {
                    ans += val;
                    ans %= mod;
                }
                for (auto v : e[u]) {
                    if (dp[0][u].count(a[v] - a[u])) {
                        dp[1][v][a[u]] += dp[0][u][a[v] - a[u]];
                        dp[1][v][a[u]] %= mod;
                        flag = 1;
                    }
                }
            }
            dp[0].clear();
            dp[0] = dp[1];
        }

        std::cout << ans << "\n";
        
    }

    return 0;
}
