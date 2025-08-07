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
const int maxn = 2e5 + 5;
const ll mod = 998244353;
std::vector<std::vector<int>> e;
std::vector<std::set<int>> s;
int loc[maxn];
bool undefined[maxn];
ll w[maxn];
int c[maxn];
int n, k;
ll ans;
int dsu[maxn];
int find(int x) {
    return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
}
void dfs(int u, int p) {
    int mx = 0, heavy_son = 0;
    bool flag = (c[u] == 0);
    for (auto v : e[u]) {
        if (v == p) continue;
        dfs(v, u);
        flag &= undefined[v];
        if (undefined[v]) {
            dsu[find(v)] = find(u);
        } else {
            if (mx < s[loc[v]].size()){
                mx = s[loc[v]].size();
                loc[u] = loc[v];
                heavy_son = v;
            }
        }
    }
    int count = 0, pair_col = 0;
    for (auto v : e[u]) {
        if (v == p) continue;
        if (v == heavy_son) continue;
        if (undefined[v]) continue;
        for (auto it : s[loc[v]]) {
            if (s[loc[u]].count(it) && it != pair_col) {
                count += 1;
                pair_col = it;
            }
            s[loc[u]].insert(it);
        }
    }
    undefined[u] = flag;
    if (!undefined[u]) {
        if (count >= 2) {
            ans += w[u];
            if (!c[u]) c[u] = pair_col;
        }
        else if (count == 1) {
            if (c[u] == 0) {
                c[u] = pair_col;
            } else if (c[u] != pair_col) {
                ans += w[u];
            }
        } else {
            if (!c[u]) {
                if (!s[loc[u]].empty()) {
                    c[u] = *s[loc[u]].begin();
                } else {
                    assert(false);
                }
            }
        }
        s[loc[u]].insert(c[u]);
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
        std::cin >> n >> k;
        e.clear();
        e.resize(n + 1);
        s.clear();
        s.resize(n + 1);
        ans = 0;
        for (int i = 1; i <= n; ++i) {
            loc[i] = i;
            undefined[i] = 0;
            dsu[i] = i;
        }
        for (int i = 1; i <= n; ++i) {
            std::cin >> w[i];
        }
        for (int i = 1; i <= n; ++i) {
            std::cin >> c[i];
        }
        for (int i = 1; i < n; ++i) {
            int u, v;
            std::cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(1, 0);
        if (undefined[1]) c[1] = 1;
        for (int i = 1; i <= n; ++i) {
            if (c[i]) continue;
            assert(c[find(i)]);
            c[i] = c[find(i)];
        }
        std::cout << ans << '\n';
        for (int i = 1; i <= n; ++i) {
            std::cout << c[i] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
