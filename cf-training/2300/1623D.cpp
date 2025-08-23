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
const ll mod = 1e9 + 7;
ll quick_pow(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y & 1) res *= x, res %= mod;
        x *= x, x %= mod;
        y /= 2;
    }
    return res;
}
ll inv(ll x) {
    return quick_pow(x, mod - 2);
}
ll inv100;
int n, m, prob;
pii start, end;
// std::vector<std::vector<int>> vis;
pll dfs(pii p, pii delta, pii ori, int flag) {
    auto [r, c] = p;
    auto [dx, dy] = delta;
    int nr = r, nc = c;
    if (dx + r < 1 || dx + r > n) {
        dx = -dx;
    }
    if (dy + c < 1 || dy + c > m) {
        dy = -dy;
    }
    nr += dx;
    nc += dy;
    if (!flag) {
        ori = {dx, dy};
    }
    if (p == start && ori == std::make_pair(dx, dy) && flag) {
        return {1, 0};
    }

    pll res = dfs({nr, nc}, {dx, dy}, ori, 1);
    ll fac;
    if (r == end.first || c == end.second) {
        fac = (100 - prob) * inv100 % mod;
    } else {
        fac = 1;
    }
    return {res.first * fac % mod, fac * (res.second + 1) % mod};
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
        std::cin >> n >> m >> start.first >> start.second >> end.first >> end.second >> prob;
        // vis.resize(n + 1);
        // for (int i = 1; i <= n; ++i) {
        //     vis[i].resize(m + 1);
        // }
        inv100 = inv(100);
        pll res = dfs(start, {1, 1}, {1, 1}, 0);
        
        std::cout << res.second * inv((1 - res.first + mod) % mod) % mod << '\n';
    }

    return 0;
}
// 21 : 00 -  