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
int n, m, k;
int h[maxn];
std::vector<std::vector<int>> e, inve;
int in[maxn], invin[maxn];
pii dis[maxn], invdis[maxn];
void clear() {
    for (int i = 1;i <= n; ++i) {
        in[i] = 0;
        invin[i] = 0;
        dis[i] = {0, 0};
        invdis[i] = {n, k};
    }
    inve.clear();
    e.clear();
}
void bfs() {
    std::queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (!in[i]) {
            q.push(i);
            dis[i] = {0, h[i]};
        }   
    }
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        for (auto v : e[u]) {
            if (dis[v] < dis[u]) dis[v] = dis[u];
            --in[v];
            if (in[v] == 0) {
                q.push(v);
                if (dis[v].second != h[v]) {
                    dis[v].first += (dis[v].second > h[v]);
                    dis[v].second = h[v];
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (!invin[i]) {
            q.push(i);
            invdis[i] = dis[i];
        } else {
            invdis[i] = {n, k};
        }
        invdis[i] = dis[i];
    }
    // while (!q.empty()) {
    //     auto u = q.front();
    //     q.pop();
    //     for (auto v : inve[u]) {
    //         invdis[v] = std::min(invdis[u], invdis[v]);
    //         invin[v]--;
    //         if (invin[v] == 0) {
    //             q.push(v);
    //             if (invdis[v].second != h[v]) {
    //                 invdis[v].first -= (invdis[v].second < h[v]);
    //                 invdis[v].second = h[v];
    //             }
    //         }
    //     }
    // }
    
    std::set<std::pair<pii, int>> s;
    for (int i = 1; i <= n; ++i) {
        s.insert({invdis[i], i});
    }
    ll ans = 1e18;
    while (true) {
        auto [min, idx] = *s.begin();
        auto [max, useless] = *(--s.end());
        ans = std::min(ans, 1ll * (max.first - min.first) * k + max.second - min.second);
        if (min.first != 0) break;
        std::queue<int> q;
        q.push(idx);
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            s.erase({invdis[u], u});
            invdis[u].first += 1;
            s.insert({invdis[u], u});
            for (auto v : e[u]) {
                if (invdis[v] < invdis[u]) {
                    q.push(v);
                }
            }
        }
    }
    std::cout << ans << '\n';
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
        std::cin >> n >> m >> k;
        for (int i = 1; i <= n; ++i) {
            std::cin >> h[i];
        }
        e.resize(n + 1);
        inve.resize(n + 1);
        for (int i = 1; i <= m; ++i) {
            int u, v;
            std::cin >> u >> v;
            inve[v].push_back(u);
            e[u].push_back(v);
            in[v]++;
            invin[u]++;
        }
        bfs();
        clear();
    }

    return 0;
}
