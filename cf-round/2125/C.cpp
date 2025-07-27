#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <bitset>
#include <memory.h>
#include <assert.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
const ll mod = 998244353;
ll l, r;
std::vector<int> prime = {2, 3, 5, 7};
ll dfs(int dep, int count, ll cur, ll x) {
    if (dep == 4) {
        ll res = x / cur;
        if (count % 2 == 1) res *= -1;
        return res;
    }
    ll res = 0;
    res += dfs(dep + 1, count, cur, x);
    res += dfs(dep + 1, count + 1, cur * prime[dep], x);
    return res;
}
ll cal(ll x) {
    if (x == 1) return 1;
    return dfs(0, 0, 1, x);
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
        std::cin >> l >> r;
        std::cout << cal(r) - cal(l - 1) << '\n';
    }

    return 0;
}
