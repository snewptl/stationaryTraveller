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
const int maxn = 3e5 + 5;
const ll mod = 998244353;
int n, m;
std::vector<std::vector<int>> e;
int dep[maxn], vis[maxn];
void bfs() {
    std::queue<int> q;
    q.push(1);
    dep[1] = 1;
    vis[1] = 1;
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        int flag = 0;
        for (auto v : e[p]) {
            if (vis[v]) flag = 1;
            if (dep[v]) continue;
            dep[v] = dep[p] + 1;
            q.push(v);
        }
        if (!flag) vis[p] = 1;
    }
}
void output() {
    std::vector<int> vec;
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) vec.push_back(i);
        if (!dep[i]) {
            std::cout << "NO\n";
            return;
        }
    }
    std::cout << "YES\n";
    std::cout << vec.size() << '\n';
    for (auto it : vec) std::cout << it << ' ';
    std::cout << '\n';
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
        for (int i = 1; i <= n; ++i) dep[i] = vis[i] = 0;
        for (int i = 1; i <= m; ++i) {
            int u, v;
            std::cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        bfs();
        output();
    }

    return 0;
}
// 14 : 12 - 14 : 43