#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <assert.h>
#include <cmath>
#include <random>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef std::pair<ull, int> pui;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
const ll mod = 1e9 + 7;
int n;
ull color[maxn];
std::vector<std::vector<int>> e;
std::map<std::pair<ull, int>, int> count;
std::map<ull, ull> mp;
ull hash[maxn];
int sz[maxn];
ull sum[maxn];
ll ans[maxn];
// ull quick_pow(ull x, ull y) {
//     ll res = 1;
//     while (y) {
//         if (y & 1) res *= x, x %= mod;
//         x *= x, x %= mod;
//         y /= 2;
//     } 
//     return y;
// }
void dfs(int u, int p) {
    hash[u] = mp[color[u]] * mp[color[u]] * (color[u] + color[u] * color[u] + color[u] * color[u] * color[u]);
    sum[u] = hash[u];
    sz[u] = 1;
    for (auto v : e[u]) {
        if (v == p) continue;
        dfs(v, u);
        sum[u] += sum[v];
        sz[u] += sz[v];
    }
    ans[1] += count[{sum[u], sz[u]}];
    ans[1] = (ans[1] % mod + mod) % mod;
    if (sz[u] != n) {
        count[{sum[u], sz[u]}] += 1;
    }
}
void change_root(int u, int p) {
    for (auto v : e[u]) {
        if (v == p) continue;
        pui cur_v = {sum[v], sz[v]};
        ans[v] = ans[u] - (count[cur_v] - 1);
        ans[v] = (ans[v] % mod + mod) % mod;
        --count[cur_v];
        pui cur_u = {sum[u] - sum[v], n - sz[v]};
        ans[v] += count[cur_u];
        ans[v] = (ans[v] % mod + mod) % mod;
        ++count[cur_u];
        ull temp = sum[v];
        sum[v] = sum[u];
        change_root(v, u);
        sum[v] = temp;
        ++count[cur_v];
        --count[cur_u];
    }
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, (1 << 30));

    int T; std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) ans[i] = 0;
        mp.clear();
        count.clear();
        e.clear();
        e.resize(n + 1);
        for (int i = 1; i <= n; ++i) std::cin >> color[i];
        for (int i = 1; i <= n; ++i) mp[color[i]] = dis(gen);
        for (int i = 1; i < n; ++i) {
            int u, v;
            std::cin >> u >> v;
            e[u].push_back(v); 
            e[v].push_back(u);
        }
        dfs(1, 0);
        change_root(1, 0);
        int q;
        std::cin >> q;
        for (int i = 1; i <= q; ++i) {
            int x;
            std::cin >> x;
            std::cout << ans[x] << '\n';
        }
    }

    return 0;
}
