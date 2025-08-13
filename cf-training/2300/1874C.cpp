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
const int maxn = 5e3 + 5;
const ll mod = 998244353;
int n, m;
std::vector<std::vector<int>> e;
std::vector<std::vector<double>> vec;
int deg[maxn];
double dp[maxn], g[maxn][maxn];
void bfs() {
    std::queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (deg[i]) continue;
        q.push(i);
    }
    dp[n] = 1;
    while (!q.empty()) {
        int p = q.front(); q.pop();
        if (p != n) {
            std::sort(all(vec[p]));
            std::reverse(all(vec[p]));
            double res = 0;
            for (int i = 0; i < vec[p].size(); ++i) {
                res += vec[p][i] * g[vec[p].size()][i + 1];
            }
            dp[p] = res;
        }
        for (auto v : e[p]) {
            deg[v] -= 1;
            vec[v].push_back(dp[p]);
            if (deg[v] == 0) {
                q.push(v);
            }
        }
    }
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(NULL);

    g[1][1] = 1;
    for (int i = 2; i <= 5e3; ++i) {
        g[i][1] = 1.0 / i;
        for (int j = 2; j <= i; ++j) {
            g[i][j] = g[i - 2][j - 2] * (j - 2) / i + g[i - 2][j - 1] * (i - j) / i;
        }
    }
    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> m;
        e.clear();
        e.resize(n + 1);
        vec.clear();
        vec.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            deg[i] = 0;
            dp[i] = 0;
        }
        for (int i = 1; i <= m; ++i) {
            int u, v;
            std::cin >> u >> v;
            e[v].push_back(u);
            deg[u] += 1;
        }
        bfs();
        printf("%.10lf\n", dp[1]);
        // std::cout << dp[1] << '\n';
    }

    return 0;
}
// 00 : 02 - 1 : 07