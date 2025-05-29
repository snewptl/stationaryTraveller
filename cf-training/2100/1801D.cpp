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
typedef std::tuple<ll, ll, ll, int> quad;// minperformance, remainingcoin, maxw, citynumber
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
const ll mod = 998244353;
int n, m, p;
ll w[805];
std::vector<std::vector<pii>> e;
pll dis[805][805];
std::map<ll, int> mp;
int count;
struct TupleCompare {
    bool operator()(const quad& a, const quad& b) {
        if (std::get<0>(a) == std::get<0>(b)) {
            return std::get<1>(a) > std::get<1>(b);
        } else {
            return std::get<0>(a) < std::get<0>(b);
        }
    }
};
void clear() {
    count = 0;
    mp.clear();
    e.clear();
}
int hash(int x) {
    if (!mp.count(x)) mp[x] = ++count;
    return mp[x];
}
void bfs() {
    std::priority_queue<quad, std::vector<quad>, TupleCompare> q;
    q.push(quad(0, p, w[1], 1));
    dis[1][hash(w[1])] = {0, -p};
    while (!q.empty()) {
        auto [min_performance, remaining_coins, max_w, u] = q.top(); 
        q.pop();
        for (auto [v, s] : e[u]) {
            ll new_w = std::max(max_w, w[v]);
            ll new_coins = remaining_coins;
            ll new_performance = min_performance;
            if (s > remaining_coins) {
                ll delta = (s - remaining_coins + max_w - 1) / max_w;
                new_coins = remaining_coins + delta * max_w - s;
                new_performance += delta;
            } else {
                new_coins -= s;
            }
            if (dis[v][hash(new_w)] > std::make_pair(new_performance, -new_coins)) {
                dis[v][hash(new_w)] =  std::make_pair(new_performance, -new_coins);
                q.push(quad(new_performance, new_coins, new_w, v));
            }
        }
    }
    ll ans = 1e18;
    for (int i = 1; i <= count; ++i) {
        ans = std::min(ans, dis[n][i].first);
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
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j){
                dis[i][j] = {1e18, 0};
            }
        }
        e.resize(n + 1);
        for (int i = 1; i <= m; ++i) {
            int u, v, s;
            std::cin >> u >> v >> s;
            e[u].push_back({v, s});
        }
        bfs();
        clear();
    }

    return 0;
}
