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
int l, r;
ll p3[31];
ll dfs(int dep, int le, int ri) {
    if (dep == -1) return 1;
    int cur = 1 << dep;
    ll res = 0;
    if (!le && !ri) {
        if (cur - 1 >= l)
            res += dfs(dep - 1, 0, 0);
        if (cur - 1 >= l && cur <= r) {
            res += dfs(dep - 1, 0, cur);
        }
    } else {
        if (le >= l && ri + cur * 2 - 1 <= r) {
            res = p3[dep + 1];
        } else {
            if (le + cur - 1 >= l && ri + cur <= r) {
                res += dfs(dep - 1, le, ri + cur);
            }
            if (le + cur - 1 >= l) {
                res += dfs(dep - 1, le, ri);
            }
            res += dfs(dep - 1, le + cur, ri);
        }
    }
    return res;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    p3[0] = 1;
    for (int i = 1; i <= 30; ++i) {
        p3[i] = p3[i - 1] * 3;
    }
    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> l >> r;
        ll ans = dfs(30, 0, 0) * 2;
        if (l == 0) ans -= 1;
        std::cout << ans << '\n';   
    }

    return 0;
}
// 19 : 36 - 