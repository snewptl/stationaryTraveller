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
int n, q;
ll a[maxn];
std::vector<std::vector<int>> e;
std::vector<std::vector<pii>> vec;
int dep[maxn];
pii opt[maxn];
std::map<pii, ll> mp;
int parent[maxn];
void dfs(int u) {
    for (auto v : e[u]) {
        dep[v] = dep[u] + 1;
        dfs(v);
    }
}
bool try_hash(pii p) {
    auto [u, v] = p;
    if (u > v) std::swap(u, v);
    if (mp.count({u, v})) {
        return 0;
    }
    else {
        mp[{u, v}] = 1;
        mp[{v, u}] = 1;
        return 1;
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
    // std::cin >> T;
    while (T--) {
        std::cin >> n >> q;
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        e.clear();
        e.resize(n + 1);
        vec.clear();
        vec.resize(n + 1);
        for (int i = 2; i <= n; ++i) {
            int p; std::cin >> p;
            e[p].push_back(i);
            parent[i] = p;
        }
        dep[1] = 1;
        dfs(1);
        for (int i = 1; i <= q; ++i) {
            int u, v;
            std::cin >> u >> v;
            if(try_hash({u, v})) vec[dep[u]].push_back({u, v});
            opt[i] = {u, v};
        }
        for (int i = n; i >= 1; --i) {
            for (auto [u, v] : vec[i]) {
                int new_u = parent[u], new_v = parent[v];
                if (new_u && try_hash({new_u, new_v})) vec[i - 1].push_back({new_u, new_v}); 
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (auto [u, v] : vec[i]) {
                int new_u = parent[u], new_v = parent[v];
                ll res = a[u] * a[v];
                if (new_u) res += mp[{new_u, new_v}];
                mp[{u, v}] = res;
                mp[{v, u}] = res;
            }
        }
        for (int i = 1; i <= q; ++i) {
            std::cout << mp[opt[i]] << '\n';
        }
    }

    return 0;
}