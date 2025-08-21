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
int n, m, q;
std::vector<std::set<pii>> s;
int dsu[maxn];
pii seg[maxn], e[maxn];
int find(int x) {
    return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
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
        std::cin >> n >> m >> q;
        for (int i = 1; i <= n; ++i) {
            dsu[i] = i;
            seg[i] = {i, i};
        }
        s.clear();
        s.resize(n + 1);
        for (int i = 1; i <= m; ++i) {
            int u, v;
            std::cin >> u >> v;
            if (u > v) std::swap(u, v);
            e[i] = {u, v};
        }
        for (int i = 1; i <= q; ++i) {
            int l, r;
            std::cin >> l >> r;
            s[l].insert({r, i});
        }
        for (int i = 1; i <= m; ++i) {
            auto [u, v] = e[i];
            
        }
    }

    return 0;
}
// 13 : 16 - 