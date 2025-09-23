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
int n, m;
pii s, f;
std::vector<std::pair<pii, int>> pos[2];
std::vector<std::vector<pii>> e; 
bool y_first(std::pair<pii, int> xx, std::pair<pii, int> yy) {
    pii x = xx.first, y = yy.first;
    return y.second == x.second ? x.first < y.first : x.second < y.second;
}
void dij() {
    std::vector<ll> dis;
    std::vector<bool> used;
    dis.resize(m + 2, 1e18);
    used.resize(m + 2);
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> q;
    q.push({0, 0});
    dis[0] = 0;
    while (!q.empty()) {
        auto [_, u] = q.top();
        q.pop();
        if (used[u]) continue;
        used[u] = 1;
        for (auto [v, w] : e[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({dis[v], v}); 
            }
        }
    }
    std::cout << dis[m + 1] << '\n';
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    std::cin >> s.first >> s.second >> f.first >> f.second;
    for (int i = 1; i <= m; ++i) {
        pii cur; 
        std::cin >> cur.first >> cur.second;
        pos[0].push_back({cur, i});
    }
    pos[1] = pos[0];
    std::sort(all(pos[0]));
    std::sort(all(pos[1]), y_first);
    e.clear();
    e.resize(m + 2);
    for (int t = 0; t < 2; ++t) {
        for (int i = 1; i < m; ++i) {
            auto [x, u] = pos[t][i - 1];
            auto [y, v] = pos[t][i];
            int w = std::min(std::abs(x.first - y.first), std::abs(x.second - y.second));
            e[u].push_back({v, w});
            e[v].push_back({u, w});
        }
    }
    for (auto [x, u] : pos[0]) {
        int w = std::min(std::abs(x.first - s.first), std::abs(x.second - s.second));
        e[0].push_back({u, w});
        w = std::abs(x.first - s.first) + std::abs(x.second - s.second);
        e[u].push_back({0, w});
        w = std::min(std::abs(x.first - f.first), std::abs(x.second - f.second));
        e[m + 1].push_back({u, w});
        w = std::abs(x.first - f.first) + std::abs(x.second - f.second);
        e[u].push_back({m + 1, w});
    }
    int w = std::abs(f.first - s.first) + std::abs(f.second - s.second);
    e[0].push_back({m + 1, w});
    e[m + 1].push_back({0, w});
    dij();
    return 0;
}
// 15 : 00 - 15 : 45