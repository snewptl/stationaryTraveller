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
ll a[maxn];
int n, m, s;
int dep[maxn], fa[maxn];
std::vector<std::vector<int>> e;
std::vector<int> link;
int sgn;
void dfs(int u, int p) {
    for (auto v : e[u]) {
        if (p == v) continue;
        if (dep[v]) {
            if (link.empty() && (dep[u] - dep[v]) % 2 == 0) {
                int cur = u;
                while (cur != s) {
                    link.push_back(cur);
                    cur = fa[cur];
                }
                std::reverse(all(link));
                cur = v;
                while (cur != s) {
                    link.push_back(cur);
                    cur = fa[cur];
                }
                link.push_back(s);
            }
        } else {
            dep[v] = dep[u] + 1; 
            fa[v] = u;
            dfs(v, u);
        } 
    }
}
int b[maxn];
void init(int u) {
    b[u] = a[u];
    for (auto v : e[u]) {
        if (dep[v] != dep[u] + 1) continue;
        init(v);
        b[u] |= b[v];
    }
}
void paint(int u) {
    link.push_back(u);
    a[u] ^= 1;
    for (auto v : e[u]) {
        if (dep[v] != dep[u] + 1) continue;
        if (b[v]) paint(v);
    }
    if (a[u]) {
        link.push_back(fa[u]);
        link.push_back(u);
        link.push_back(fa[u]);
    } else {
        link.push_back(fa[u]);
        a[fa[u]] ^= 1;
    }
    a[u] = 0;
}
bool solve() {
    dfs(s, 0);
    for (int i = 1; i <= n; ++i) {
        sgn ^= a[i];
    }
    if (sgn) {
        if (link.empty()) return false;
    } else {
        link.clear();
    }
    for (auto it : link) {
        a[it] ^= 1;
    } 
    init(s);
    for (auto it : e[s]) {
        if (dep[it] != dep[s] + 1) continue;
        if (b[it]) paint(it);
    }
    // assert(a[s] == 0);
    for (int i = 1; i <= n; ++i) {
        if (a[i]) return false;
    }
    std::cout << "Yes\n";
    std::cout << link.size() << '\n';
    for (auto it : link) std::cout << it << ' ';
    std::cout << '\n';
    return true;
}
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
        std::cin >> n >> m >> s;
        for (int i = 1; i <= n; ++i) {
            dep[i] = 0;
            fa[i] = 0;
            b[i] = 0;
            std::cin >> a[i];
            a[i] %= 2;
        }
        dep[s] = 1;
        sgn = 0;
        e.clear();
        e.resize(n + 1);
        link.clear();
        for (int i = 1; i <= m; ++i) {
            int u, v;
            std::cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        for (int i = 1; i <= n; ++i) {
            std::sort(all(e[i]));
            e[i].resize(std::unique(all(e[i])) - e[i].begin());
        } 
        if (!solve()) std::cout << "No\n";
    }

    return 0;
}
