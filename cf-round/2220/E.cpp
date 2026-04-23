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
#include <iomanip> 
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
int col[maxn];
db dp[maxn][2];
void dfs(int u, int p) {
    std::vector<std::pair<db, int>> vec;
    for (auto v : e[u]) {
        if (v == p) continue;
        dfs(v, u);
        assert(dp[v][0] >= dp[v][1]);
        vec.push_back({dp[v][0] - dp[v][1], v});
    }
    if (col[u]) {
        db sum = 0;
        for (auto v : e[u]) {
            if (v == p) continue;
            sum += dp[v][1];
        }
        dp[u][0] = dp[u][1] = sum;
    } else {
        std::sort(all(vec));
        int d = e[u].size();
        int x = 0;
        db sum = 0;
        for (auto [val, v] : vec) {
            if (x == 0 || val <= 1.0 * d / x - 1.0 * d / (x + 1)) {
                sum += dp[v][0];
                x += 1;
            } else {
                sum += dp[v][1];
            }
        }
        if (x == 0) dp[u][0] = 1e18;
        else {
            sum += 1.0 * d / x;
            dp[u][0] = sum;
        }
        if (dp[u][0] > 1e18) dp[u][0] = 1e18;
        sum = 0;
        x = 1;
        for (auto [val, v] : vec) {
            if (val <= 1.0 * d / x - 1.0 * d / (x + 1)) {
                sum += dp[v][0];
                x += 1;
            } else {
                sum += dp[v][1];
            }
        }
        sum += 1.0 * d / x;
        dp[u][1] = sum;
    }
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
        std::string s;
        std::cin >> s;
        int root = 0;
        for (int i = 0; i < n; ++i) {
            col[i + 1] = s[i] - '0';
            if (col[i + 1]) root = i + 1;
        }
        e.clear();
        e.resize(n + 1);
        for (int i = 1; i < n; ++i) {
            int u, v;
            std::cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(root, 0);
        std::cout << std::setprecision(9) << dp[root][0] << '\n';
    }

    return 0;
}
