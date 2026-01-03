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
int n, m;
int count[65];
ll p[65];
// ll dp[61][61][]
ll quick_pow(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y & 1) res *= x, res %= mod;
        x *= x, x %= mod;
        y /= 2;
    }
    return res;
}
ll dfs(int dep, int last, ll x) {
    ll res = 0;
    for (int i = last; i >= 0; --i) {
        if (x <= 0) {
            res += dfs(dep + 1, i, x - )
        }
        if (i < dep || p[i - dep] * 2 <= x) break;
        res += dfs(dep + 1, i, x - p[i - dep])
    }
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    p[0] = 1;
    for (int i = 1; i <= 60; ++i) {
        p[i] = p[i - 1] * 2;
    }
    int T = 1;
    // std::cin >> T;
    while (T--) {
        std::cin >> n >> m;
        for (int i = 0; i <= 60; ++i) {
            count[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            int x;
            std::cin >> x;
            count[x] += 1;
        }
        while (m--) {
            int opt;
            ll x;
            std::cin >> opt >> x;
            if (opt == 1) {
                count[x] += 1;
            } else if (opt == 2) {
                count[x] -= 1;
            } else {
                std::cout << dfs(0, 60, x) << '\n';
            }
        }
    }

    return 0;
}
