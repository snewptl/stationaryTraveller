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
const int maxn = 3e5 + 5;
const ll mod = 998244353;
int n, q;
std::vector<std::vector<int>> e;
int a[maxn], fa[maxn], pos[maxn];
std::set<int> wrong;
std::vector<std::set<pii>> left, right;
int sz[maxn];
bool is_wrong(int x) {
    int l = pos[x], r = pos[x] + sz[x] - 1;
    if (left[x].empty()) return false;
    int mn = left[x].begin()->first, mx = right[x].rbegin()->first;
    if (mn < l || mx > r) return true;
    return false;
}
void dfs(int u) {
    sz[u] = 1;
    for (auto v : e[u]) {
        dfs(v);
        sz[u] += sz[v];
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
        e.clear();
        e.resize(n + 1);
        left.clear();
        left.resize(n + 1);
        right.clear();
        right.resize(n + 1);
        wrong.clear();
        for (int i = 1; i < n; ++i) {
            int x; std::cin >> x;
            e[x].push_back(i + 1);
            fa[i + 1] = x;
        }
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            pos[a[i]] = i;
        }
        dfs(1);
        for (int i = 1; i <= n; ++i) {
            for (auto v : e[i]) {
                left[i].insert({pos[v], v});
                right[i].insert({pos[v] + sz[v] - 1, v});
            }
            if (is_wrong(i)) wrong.insert(i);
        }
        while (q--) {
            int pos_x, pos_y;
            std::cin >> pos_x >> pos_y;
            int node_x = a[pos_x], node_y = a[pos_y];
            if (fa[node_x]) {
                left[fa[node_x]].erase({pos_x, node_x});
                right[fa[node_x]].erase({pos_x + sz[node_x] - 1, node_x});
                left[fa[node_x]].insert({pos_y, node_x});
                right[fa[node_x]].insert({pos_y + sz[node_x] - 1, node_x});
            }
            if (fa[node_y]) {
                left[fa[node_y]].erase({pos_y, node_y});
                right[fa[node_y]].erase({pos_y + sz[node_y] - 1, node_y});
                left[fa[node_y]].insert({pos_x, node_y});
                right[fa[node_y]].insert({pos_x + sz[node_y] - 1, node_y});
            }
            std::swap(a[pos_x], a[pos_y]);
            pos[node_x] = pos_y;
            pos[node_y] = pos_x;
            if (fa[node_x]) {
                if (is_wrong(fa[node_x])) wrong.insert(fa[node_x]);
                else wrong.erase(fa[node_x]);
            }
            if (fa[node_y]) {
                if (is_wrong(fa[node_y])) wrong.insert(fa[node_y]);
                else wrong.erase(fa[node_y]);
            }
            if (is_wrong(node_x)) wrong.insert(node_x);
            else wrong.erase(node_x);
            if (is_wrong(node_y)) wrong.insert(node_y);
            else wrong.erase(node_y);
            if (wrong.empty()) std::cout << "YES\n";
            else std::cout << "NO\n";
        }
    }

    return 0;
}
// 17 : 08 - 18 : 32