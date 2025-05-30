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
const int maxn = 2e3 + 5;
int n;
std::string str;
std::vector<std::vector<int>> e;
pii direct[maxn][maxn];
std::vector<std::vector<pii>> node_pairs;
int dp[maxn][maxn];
int ans;
void init() {
    e.clear();
    e.resize(n + 1);
    node_pairs.clear();
    node_pairs.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = 0;
        }
        dp[i][i] = 1;
    }
    ans = 1;
}
void dfs(int u, int rt, int top_dir, int p, int dep) {
    direct[rt][u] = {top_dir, p}; 
    node_pairs[dep + 1].push_back({rt, u});
    for (auto v : e[u]) {
        if (v == p) continue;
        dfs(v, rt, top_dir, u, dep + 1);
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
        std::cin >> n >> str;
        init();
        for (int i = 1; i < n; ++i) {
            int u, v;
            std::cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        for (int i = 1; i <= n; ++i) {
            for (auto v : e[i]) {
                dfs(v, i, v, i, 1);
            }
        }
        for (int i = 2; i <= n; ++i) {
            for (auto [u, v] : node_pairs[i]) {
                auto [new_u, new_v] = direct[u][v];
                dp[u][v] = std::max(dp[new_u][v], dp[u][new_v]);
                if (str[u - 1] == str[v - 1]) {
                    if (new_u == v) {
                        dp[u][v] = 2;
                    } else {
                        dp[u][v] = std::max(2 + dp[new_u][new_v], dp[u][v]);
                    }
                }
                ans = std::max(ans, dp[u][v]);
            }
        }
        std::cout << ans << '\n';
    }

    return 0;
}
