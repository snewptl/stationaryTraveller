#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <memory.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e3 + 5;
const ll mod = 998244353;
int n, q;
std::vector<int> e[maxn];
const ll inf = 1e9;
ll dp[2][maxn][maxn];
ll rec[2][maxn][maxn];
int in[maxn];
ll quick_pow(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y&1) {
            res *= x, res %= mod;
        }
        y /= 2;
        x *= x, x %= mod;
    }
    return res;
}
ll inv(ll x) {
    return quick_pow(x, mod - 2);
}
ll mul(ll x, ll y) {
    return x * y % mod;
}
ll add(ll x, ll y) {
    return (x + y) % mod;
}
void dfs(int u, int p, int coin) {
    for (auto v: e[u]) {
        if (v == p) continue;
        dp[1][v][coin] = dp[0][u][coin] + 1;
        // rec[1][v][coin] = add(rec[0][u][coin], 1);
        if (coin) {
            dp[0][v][coin] = dp[1][u][coin - 1] + 1;
            // rec[0][v][coin] = add(rec[1][u][coin - 1], 1);
        }
        if (in[v] > 1) {
            if (dp[0][v][coin] > dp[1][u][coin] + 1 + 2.0 * (in[v] - 1)) {
                dp[0][v][coin] = dp[1][u][coin] + 1 + 2.0 * (in[v] - 1);
                // rec[0][v][coin] = add(rec[1][u][coin], 2 + inv(in[v] - 1));
            }
        } else {
            if (dp[0][v][coin] > dp[1][u][coin] + 1) {
                dp[0][v][coin] = dp[1][u][coin] + 1;
                // rec[0][v][coin] = add(rec[1][u][coin], 1);
            }
        }
        dfs(v, u, coin);
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
        std::cin >> n >> q;
        for (int i = 1; i < n; ++i) {
            int u, v;
            std::cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
            in[u]++;
            in[v]++;
        }
        for (int i = 0; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[0][j][i] = dp[1][j][i] = inf;
            }
            dp[0][1][i] = dp[1][1][i] = 0;
            // rec[0][1][i] = rec[1][1][i] = 0;
            dfs(1, 0, i);
        }
        for (int i = 1; i <= q; ++i) {
            int v, p;
            std::cin >> v >> p;
            std::cout << dp[1][v][p] << '\n';
        }
        for (int i = 1; i <= n; ++i) {
            e[i].clear();
            in[i] = 0;
        }

    }

    return 0;
}
