#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
int n, q;
std::vector<int> e[maxn];
int fa[maxn];
int color[maxn];
int count_son[maxn];
int two_son;
int component;
int dep[maxn];
std::set<pii> s;
void clear() {
    component = 0;
    two_son = 0;
    for (int i = 1; i <= n; ++i) {
        e[i].clear();
    }
    s.clear();
}
void dfs(int u, int p) {
    count_son[u] = 0;
    fa[u] = p;
    for (auto v : e[u]) {
        if (v == p) continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
        if (color[v]) count_son[u]++;
    }
    if(count_son[u] >= 2 && color[u]) ++two_son;
    if (color[u]) {
        component += 1 - count_son[u];
        s.insert({dep[u], u});
    }
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
        std::cin >> n >> q;
        for (int i = 1; i <= n; ++i) {
            std::cin >> color[i];
        }
        for (int i = 1; i < n; ++i) {
            int u, v;
            std::cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(1, 0);
        while(q--) {
            int u; std::cin >> u;
            if (color[u]) {
                color[u] = 0;
                s.erase({dep[u], u});
                if (count_son[u] >= 2) --two_son;
                int p = fa[u];
                if (p) {
                    component += color[p] ? count_son[u] : count_son[u] - 1;
                    --count_son[p];
                    if (count_son[p] == 1 && color[p]) --two_son;
                } else {
                    component += count_son[u] - 1;
                }
            } else {
                color[u] = 1;
                s.insert({dep[u], u});
                if (count_son[u] >= 2) ++two_son;
                int p = fa[u];
                if (p) {
                    component -= color[p] ? count_son[u] : count_son[u] - 1;
                    ++count_son[p];
                    if (count_son[p] == 2 && color[p]) ++two_son;
                } else {
                    component -= count_son[u] - 1;
                }
            }            
            
            if (!s.empty() && (component == 1 && (two_son == 0 || (two_son == 1 && count_son[s.begin()->second] == 2)))) std::cout << "YES\n";
            else std::cout << "NO\n";
        }
        clear();
    }

    return 0;
}
