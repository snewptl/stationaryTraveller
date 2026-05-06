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
const int maxn = 5e5 + 5;
const ll mod = 998244353;
int n, q;
std::vector<std::vector<pli>> e;
int fa[maxn];
std::map<ll, int> mp;
int son[maxn];
ll cost[maxn];
ll min[maxn];
int run(int u, ll m) {
    if (e[u].empty()) return u;
    int pos = m % e[u].size();
    auto [w, v] = e[u][pos];
    w += cost[v];
    v = son[v];
    return run(v, m + w);
}
ll LCM(ll x, ll y) {
    ll d = std::__gcd(x, y);
    x /= d;
    if (2e18 / x <= y) return 1e18;
    return std::min(x * y, (ll)1e18);
}
void dfs(int u, ll cur, ll lcm) {
    min[u] = cur;
    if (e[u].size() == 0) return;
    std::map<ll, int> used;
    while (!used[cur % e[u].size()]) {
        if (cur >= 1e18) break;
        auto [w, v] = e[u][cur % e[u].size()];
        dfs(v, cur + w, LCM(lcm, e[u].size()));
        used[cur % e[u].size()] = 1;
        cur += lcm;
    }
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
        std::cin >> n >> q;
        e.clear();
        e.resize(n + 1);
        mp.clear();
        for (int i = 2; i <= n; ++i) {
            std::cin >> fa[i];
        }
        for (int i = 1; i <= n; ++i) {
            min[i] = -1;
        }
        for (int i = 2; i <= n; ++i) {
            ll w;
            std::cin >> w;
            e[fa[i]].push_back({w, i});
        }
        for (int i = n; i >= 1; --i) {
            if (e[i].size() != 1) {
                son[i] = i;
                cost[i] = 0;
            } else {
                son[i] = son[e[i][0].second];
                cost[i] = cost[e[i][0].second] + e[i][0].first;
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (min[i] != -1 && e[i].size() == 0) mp[min[i]] = i;
        }
        dfs(1, 0, 1);
        for (int i = 1; i <= q; ++i) {
            ll m;
            std::cin >> m;
            if (!mp.count(m)) mp[m] = run(1, m);
            std::cout << mp[m] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}