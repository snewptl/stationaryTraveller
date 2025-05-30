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
const int maxn = 2e5 + 5;
const ll mod = 998244353;
int n, m, p;
ll w[805];
std::vector<std::vector<pii>> e;
ll dis[805][805];
pll dp[805];
int touch[805];
void clear() {
    e.clear();
}
void dij(int i) {
    std::set<pli> q;
    q.insert({0, i});
    dis[i][i] = 0;
    while(!q.empty()) {
        auto [w, u] = *q.begin();
        q.erase(q.begin());
        for (auto [v, s] : e[u]) {
            if (dis[i][v] > dis[i][u] + s) {
                dis[i][v] = dis[i][u] + s;
                q.insert({dis[i][v], v});
            }
        }
    }
}
void solve() {
    std::vector<pli> vec;
    vec.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        vec[i] = {w[i], i};
    }
    std::sort(all(vec));
    ll ans = 1e18;
    int flag = 0;
    dp[1] = {0, p};
    touch[1] = 1;
    for (int i = 1; i <= n; ++i) {
        if (vec[i].first >= w[1]) {
            flag = 1;
        }
        if (!flag) continue;
        int u = vec[i].second;
        if (!touch[u]) continue;
        for (int j = i + 1; j <= n; ++j) {
            int v = vec[j].second;
            if (dis[u][v] == 1e18) continue;
            touch[v] = 1;
            pll temp;
            if (dp[u].second < dis[u][v]) {
                ll delta = (dis[u][v] - dp[u].second + w[u] - 1) / w[u];
                temp = {dp[u].first + delta, dp[u].second + delta * w[u] - dis[u][v]};
            } else {
                temp = {dp[u].first, dp[u].second - dis[u][v]};
            }
            if (temp.first < dp[v].first) dp[v] = temp;
            else if (temp.first == dp[v].first) {
                if (temp.second > dp[v].second) dp[v] = temp;
            } 
        }
        if (dis[u][n] == 1e18) continue;
        if (dp[u].second > dis[u][n]) {
            ans = std::min(ans, dp[u].first);
        } else {
            ll delta = (dis[u][n] - dp[u].second + w[u] - 1) / w[u];
            ans = std::min(ans, dp[u].first + delta);
        }
    }
    std::cout << (ans == 1e18 ? -1 : ans) << '\n';
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
        std::cin >> n >> m >> p;
        for (int i = 1; i <= n; ++i) {
            std::cin >> w[i];
        }
        e.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1;j <= n; ++j) {
                dis[i][j] = 1e18;
            }
            touch[i] = 0;
            dp[i] = {1e18, 0};
        }
        for (int i = 1; i <= m; ++i) {
            int u, v, s;
            std::cin >> u >> v >> s;
            e[u].push_back({v, s});
        }
        for (int i = 1; i <= n; ++i) dij(i);
        solve();
        clear();
    }

    return 0;
}
