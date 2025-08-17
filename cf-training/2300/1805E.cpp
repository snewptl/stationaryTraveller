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
int a[maxn];
std::vector<std::vector<pii>> e;
int fa[maxn][20], ind[maxn], dep[maxn];
int ans[maxn];
void dfs(int u, int p) {
    for (auto [v, id] : e[u]) {
        if (v == p) continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
        fa[v][0] = u;
        ind[v] = id;
    }
}
int lca(int x, int y) {
    if (dep[x] < dep[y]) std::swap(x, y);
    for (int j = 19; j >= 0; --j) {
        if (dep[fa[x][j]] > dep[y]) x = fa[x][j];
    }
    if (dep[x] > dep[y]) x = fa[x][0];
    for (int j = 19; j >= 0; --j) {
        if (fa[x][j] != fa[y][j]) {
            x = fa[x][j];
            y = fa[y][j];
        }
    }
    if (x != y) x = fa[x][0];
    return x;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    e.resize(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v;
        std::cin >> u >> v;
        e[u].push_back({v, i});
        e[v].push_back({u, i});
    }
    dep[1] = 1;
    dfs(1, 0);
    for (int j = 1; j < 20; ++j) {
        for (int i = 1; i <= n; ++i) {
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
        }
    }
    std::map<int, std::vector<int>> mp;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        mp[-a[i]].push_back(i);
    }
    int last = 0, fin = 0;
    std::vector<pii> path, temp, res;
    for (auto [v, vec] : mp) {
        int val = -v;
        if (vec.size() == 2) {
            if (dep[vec[0]] < dep[vec[1]]) std::swap(vec[0], vec[1]);
            int top = lca(vec[0], vec[1]);
            if (!last) {
                for (int j = 0; j < 2; ++j) {
                    int cur = vec[j];
                    while (cur != top) {
                        ans[ind[cur]] = -1;
                        cur = fa[cur][0];
                    }
                }
                for (int i = 2; i <= n; ++i) {
                    if (ans[ind[i]] != -1) {
                        ans[ind[i]] = val;
                    }
                }
                for (int j = 0; j < 2; ++j) {
                    int cur = vec[j];
                    while (cur != top) {
                        ans[ind[cur]] = 0;
                        cur = fa[cur][0];
                    }
                }
                if (top != vec[1]) {
                    path.push_back({top, vec[0]});
                    path.push_back({top, vec[1]});
                } else {
                    path.push_back({vec[1], vec[0]});
                }
            } else {
                res.clear();
                temp.clear();
                if (top != vec[1]) {
                    temp.push_back({top, vec[0]});
                    temp.push_back({top, vec[1]});
                } else {
                    temp.push_back({vec[1], vec[0]});
                }
                int lower_top = temp[0].first, higher_top = path[0].first;
                if (dep[lower_top] < dep[higher_top]) std::swap(lower_top, higher_top);
                if (lca(temp[0].first, path[0].first) != higher_top) {
                    for (int i = 1; i < n; ++i) {
                        if (!ans[i]) ans[i] = val;
                    }
                    break;
                }
                for (auto [top_x, x] : path) {
                    for (auto [top_y, y] : temp) {
                        if (dep[lca(x, y)] > dep[lower_top]) {
                            res.push_back({lower_top, lca(x, y)});
                        }
                    }
                }
                // if (val == 271550471) {
                //     for (auto [top_x, x] : path) {
                //         std::cout << top_x << ' ' << x << "# ";
                //     }
                //     std::cout << "* ";                    
                //     for (auto [top_x, x] : temp) {
                //         std::cout << top_x << ' ' << x << "# ";
                //     }
                //     std::cout << "** ";  
                //     for (auto [top_x, x] : res) {
                //         std::cout << top_x << ' ' << x << "# ";
                //     }
                // }
                // assert(res.size() <= 2);
                // sort(all(res));
                // int pre = res.size();
                // res.resize(std::unique(all(res)) - res.begin());
                // assert(pre == res.size());
                if (res.empty()) {
                    for (int i = 1; i < n; ++i) {
                        if (!ans[i]) ans[i] = val;
                    }
                    break;
                }
                for (auto [top_x, x] : path) {
                    int cur = x;
                    while (cur != top_x) {
                        int flag = 0;
                        for (auto [top_y, y] : res) {
                            if (cur == y) flag = 1;
                        }
                        if (flag == 0) {
                            ans[ind[cur]] = val;
                            cur = fa[cur][0];
                        } else {
                            cur = lower_top;
                        }
                    }
                } 
                path = res;
            }
            last = val;
        } else if (vec.size() > 2) {
            for (int i = 1; i < n; ++i) if (!ans[i]) ans[i] = val;
            break;
        }
    }
    
    for (int i = 1; i < n; ++i) {
        std::cout << ans[i] << '\n';
    }

    return 0;
}
// 19 : 00 - 