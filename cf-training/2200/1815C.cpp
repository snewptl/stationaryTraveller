#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <assert.h>
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
std::vector<std::vector<int>> e, vec;
int dis[maxn];
void bfs() {
    std::queue<int> q;
    q.push(1);
    while(!q.empty()) {
        auto u = q.front();
        q.pop();
        for (auto v : e[u]) {
            if (dis[v]) continue;
            q.push(v);
            dis[v] = dis[u] + 1;
        }
    }
    for (int i = 1; i <= n; ++i) vec[dis[i]].push_back(i);
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
        vec.clear();
        vec.resize(n + 1);
        for (int i = 1; i <= n; ++i) dis[i] = 0;
        dis[1] = 1;
        for (int i = 1; i <= m; ++i) {
            int u, v;
            std::cin >> u >> v;
            e[v].push_back(u);
        }
        bfs();
        std::vector<int> cur, ans;
        for (int i = n; i >= 1; --i) {
            if (vec[i].empty()) continue;
            for (auto it : vec[i]) cur.push_back(it);
            for (int j = cur.size() - 1; j >=0; --j) {
                ans.push_back(cur[j]);
            }
        }
        if (!vec[0].empty()) std::cout << "INFINITE\n";
        else {
            std::cout << "FINITE\n";
            std::cout << ans.size() << '\n';
            for (auto it : ans) std::cout << it << " ";
            std::cout << '\n';
        }
    }

    return 0;
}
// 10 : 25