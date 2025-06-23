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
const int maxn = 3e5 + 5;
const ll mod = 998244353;
std::vector<std::vector<int>> e;
int n, m, q;
int dep[maxn], fa[maxn], vis[maxn];
pii opt[maxn];
void bfs() {
    std::queue<int> q;
    q.push(1);
    dep[1] = 1;
    while(!q.empty()) {
        auto p = q.front(); q.pop();
        for (auto v : e[p]) {
            if (dep[v]) continue;
            dep[v] = dep[p] + 1;
            fa[v] = p;
            q.push(v);
        }
    }
}
int lca(int x, int y) {
    if (x == y) return x;
    if (dep[x] < dep[y]) std::swap(x, y);
    if (dep[x] != dep[y]) return lca(fa[x], y);
    else return lca(fa[x], fa[y]);
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    e.clear();
    e.resize(n + 1);
    for (int i = 1; i <= m; ++i) {
        int x, y;
        std::cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    bfs();
    std::cin >> q;
    for (int i = 1; i <= q; ++i) {
        int a, b;
        std::cin >> a >> b;
        opt[i] = {a, b};
        ++vis[a];
        ++vis[b];
    }
    int count = 0;
    for (int i = 1; i <= n; ++i) count += vis[i] % 2;
    if (!count) {
        std::cout << "YES\n";
        for (int i = 1; i <= q; ++i) {
            auto [a, b] = opt[i];
            int u = lca(a, b);
            int cur = a;
            std::vector<int> pre, nxt;
            while (cur != u) pre.push_back(cur), cur = fa[cur];
            cur = b;
            while (cur != u) nxt.push_back(cur), cur = fa[cur];
            std::reverse(all(nxt));
            std::cout << pre.size() + nxt.size() + 1 << '\n';
            for (auto it : pre) std::cout << it << ' ';
            std::cout << u << ' ';
            for (auto it : nxt) std::cout << it << ' '; 
            std::cout << '\n';
        }
    } else {
        std::cout << "NO\n" << count / 2 << '\n';
    }


    return 0;
}
