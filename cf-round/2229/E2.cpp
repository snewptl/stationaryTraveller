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
ll dp[maxn][2];
std::vector<std::vector<int>> e;
int n;
int deg[maxn];
std::set<int> s;
int max_node[maxn];
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
        s.clear();
        for (int i = 1; i < n; ++i) {
            int u, v;
            std::cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        for (int i = 1; i <= n; ++i) {S
            max_node[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = dp[i][1] = 0;
        }
        int max = 0;
        for (int i = 1; i <= n; ++i) {
            deg[i] = e[i].size() - 1;
            if (deg[i] == 0) s.insert(i), max = std::max(max, i);
        }
        int last = max;
        while (!s.empty()) {
            auto it = *s.begin();
            if (it == last) break;
            s.erase(s.begin());
            for (auto v : e[it]) {
                deg[v] -= 1;
                max_node[v] = std::max(max_node[it], it);
                if (deg[v] == 0) s.insert(v);
            }
        }
        dp[last][1] = 1;

        while (s.size() > 1) { 
            auto it = *s.begin();
            s.erase(s.begin());
            for (auto v : e[it]) {
                deg[v] -= 1;
                max_node[v] = std::max(max_node[it], it);
                if (deg[v] == 0) s.insert(v);
            }
            if (it > last) {
                if (last == max_node[it]) {
                    dp[it][0] = dp[it][1] = dp[last][1];
                } else {
                    dp[it][0] = dp[it][1] = (dp[last][0] + dp[last][1]) % mod; 
                }
                last = it;
            }
        }


        ll ans = (dp[last][1] + dp[last][0]) % mod;
        std::cout << ans << '\n';
    }

    return 0;
}
