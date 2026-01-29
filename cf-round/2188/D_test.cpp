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
ll x, y;
ll p[32];
ll check(pll p) {
    return std::abs(p.first - x) + std::abs(p.second - y);
}
pll dfs(ll dep, ll p, ll sp, ll q, ll sq, ll turn, ll last) {
    if (dep == -1) {
        return {p, q};
    }
    if (turn == 0) {
        if (sp != 0 && sq != 0) {
            if (sp == 1) {
                return {p + (1ll << (dep + 1)) - 1, q};
            } else if (sq == 1) {
                return {p, q + (1ll << (dep + 1)) - 1};
            } else {
                return {p, q};
            }
        }
        if (sp == -1) {
            return dfs(dep, p, sp, q, sq, 1, 0);
        } else if (sp == 0) {
            pii res1, res2;
            if (x & (1ll << dep)) {
                res1 = dfs(dep, p, 1, q, sq, 1, 0);
                res2 = dfs(dep, p + (1ll << dep), sp, q, sq, 1, 1);
            } else {
                res1 = dfs(dep, p, sp, q, sq, 1, 0);
                res2 = dfs(dep, p + (1ll << dep), -1, q, sq, 1, 1);
            }
            if (check(res1) < check(res2)) return res1;
            else return res2;
        } else {
            if (sq != 0) {
                return dfs(dep, p + (1ll << dep), sp, q, sq, 1, 1);
            }
            pii res1, res2;
            if (x & (1ll << dep)) {
                res1 = dfs(dep, p, sp, q, sq, 1, 0);
                res2 = dfs(dep, p + (1ll << dep), sp, q, sq, 1, 1);
            } else {
                res1 = dfs(dep, p, sp, q, sq, 1, 0);
                res2 = dfs(dep, p + (1ll << dep), sp, q, sq, 1, 1);
            }
            if (check(res1) < check(res2)) return res1;
            else return res2;
        }
    } else {
        if (sq == -1) {
            return dfs(dep - 1, p, sp, q, sq, 0, 0);
        } else if (sq == 0) {
            pii res1, res2;
            if (y & (1ll << dep)) {
                res1 = dfs(dep - 1, p, sp, q, 1, 0, 0);
                if (!last) res2 = dfs(dep - 1, p, sp, q + (1ll << dep), sq, 0, 0);
            } else {
                res1 = dfs(dep - 1, p, sp, q, sq, 0, 0);
                if (!last) res2 = dfs(dep - 1, p, sp, q + (1ll << dep), -1, 0, 0);
            }
            if (last || check(res1) < check(res2)) return res1;
            else return res2;
        } else {
            if (!last) return dfs(dep - 1, p, sp, q + (1ll << dep), sq, 0, 0);
            else return dfs(dep - 1, p, sp, q, sq, 0, 0);
        }
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
    // std::cin >> T;
    T = 1e4;
    while (T--) {
        std::cin >> x >> y;
        x = (1 << 29);
        y = (1 << 30) - 1;
        pll res = dfs(30, 0, 0, 0, 0, 0, 0);
        std::cout << res.first << ' ' << res.second << '\n';
    }

    return 0;
}
