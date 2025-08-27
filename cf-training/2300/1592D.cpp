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
int n;
std::vector<std::set<pii>> e;
int vis[maxn];
int dep[maxn];
void bfs() {
    std::queue<int> q;
    q.push(1);
    dep[1] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto [v, ind] : e[u]) {
            if (dep[v]) continue;
            dep[v] = dep[u] + 1;
            q.push(v);
        }
    }
}
void dfs(int u, std::vector<int>& vec, int& count, int bound) {
    for (auto [v, ind] : e[u]) {
        if (dep[v] < dep[u]) continue;
        if (vis[ind]) continue;
        if (count >= bound) return;
        vis[ind] = 2;
        vec.push_back(v);
        count += 1;
        if (count >= bound) return;
        dfs(v, vec, count, bound);
    }
}
int ask(std::vector<int>& vec) {
    std::sort(all(vec));
    vec.resize(std::unique(all(vec)) - vec.begin());
    std::cout << "? " << vec.size() << '\n';
    for (auto it : vec) {
        std::cout << it << ' ';
    }
    std::cout << std::endl;
    int res;
    std::cin >> res;
    return res;
}
void output() {
    for (int i = 1; i <= n; ++i) {
        for (auto [v, ind] : e[i]) {
            if (!vis[ind]) {
                std::cout << "! " << i << " " << v << std::endl;
                return;
            }
        }
    }
}
int main() {
    #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    e.resize(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v;
        std::cin >> u >> v;
        e[u].insert({v, i});
        e[v].insert({u, i});
    }
    bfs();
    std::vector<pii> all_node;
    for (int i = 1; i <= n; ++i) {
        all_node.push_back({dep[i], i});
    }
    std::sort(all(all_node));
    int sz = n - 1;
    std::vector<int> vec;
    for (int i = 1; i <= n; ++i) vec.push_back(i);
    int mx = ask(vec);
    while (sz > 1) {
        int count = 0;
        std::vector<int> vec;
        for (auto [_, i] : all_node) {
            int pre = count;
            vec.push_back(i);
            dfs(i, vec, count, sz / 2);
            if (pre == count) {
                vec.pop_back();
            }
        }
        int new_mx = ask(vec);
        if (new_mx != mx) {
            for (int i = 1; i < n; ++i) {
                if (vis[i] == 2) vis[i] = 1;
            }
            sz = sz - sz / 2;
        } else {
            for (int i = 1; i < n; ++i) {
                if (!vis[i]) vis[i] = 1;
                else if (vis[i] == 2) vis[i] = 0;
            }
            sz = sz / 2;
        }
    }
    output();


    return 0;
}
// 20 : 32 - 21 : 12