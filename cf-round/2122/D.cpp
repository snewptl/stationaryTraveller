#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <bitset>
#include <memory.h>
#include <assert.h>
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
std::vector<std::vector<pii>> e;
std::vector<std::vector<pii>> dp;
void bfs() {
    std::priority_queue<std::pair<pii, pii>, std::vector<std::pair<pii, pii>>, std::greater<std::pair<pii, pii>>> q;
    q.push({{0, 0}, {1, 0}});
    dp[1][0] = {0, 0};
    while (!q.empty()) {
        auto [dis, p2] = q.top(); q.pop();
        auto [u, time] = p2;
        if (dis > dp[u][time]) continue;
        int sz_u = e[u].size();
        int v = e[u][dp[u][time].first % sz_u].second;
        int sz_v = e[v].size();

        pii new_dis = {dp[u][time].first + 1, dp[u][time].second};
        int new_time = (dp[u][time].first + 1) % sz_v;
        if (dp[v][new_time] > new_dis) {
            dp[v][new_time] = new_dis;
            q.push({new_dis, {v, new_time}});
        } 
        if (e[v].size() == 1) {
            new_time = (dp[u][time].first + 2) % sz_u;
            new_dis = {dp[u][time].first + 2, dp[u][time].second};
            if (dp[u][new_time] > new_dis) {
                dp[u][new_time] = new_dis;
                q.push({new_dis, {u, new_time}});
            }
        }

        new_time = (dp[u][time].first + 1) % sz_u;
        new_dis = {dp[u][time].first + 1, dp[u][time].second + 1};
        if (dp[u][new_time] > new_dis) {
            dp[u][new_time] = new_dis;
            q.push({new_dis, {u, new_time}});
        }

    }
    pii ans = {1e9, 1e9};
    for (auto it : dp[n]) {
        ans = std::min(ans, it);
    }
    std::cout << ans.first << ' ' << ans.second << '\n';
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
        std::cin >> n >> m;
        e.clear();
        e.resize(n + 1);
        dp.clear();
        dp.resize(n + 1);
        for (int i = 1; i <= m; ++i) {
            int u, v;
            std::cin >> u >> v;
            e[u].push_back({i, v});
            e[v].push_back({i, u});
        }
        for (int i = 1; i <= n; ++i) {
            sort(all(e[i]));
            dp[i].assign(e[i].size(), {1e9, 1e9});
        }
        bfs();
    }

    return 0;
}