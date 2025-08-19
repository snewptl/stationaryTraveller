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
ll cal(ll x, int dep) {
    if (x < dep) return 0;
    ll res = 1;
    for (int i = 0; i < dep; ++i) res *= x - i;
    for (int i = 1; i <= dep; ++i) res /= i;
    return res; 
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
        ll del = 0;
        for (int i = l; i <= r; ++i) {
            int count = 0;
            for (int j = 1; j * j <= i; ++j) {
                if (i % j != 0) continue;
                if (j != i && j >= l) count += 1;
                if (i / j != j && i / j >= l && i / j != i) count += 1;
            }
            del += cal(count, 2);
        }
        ll ans = cal(r - l + 1, 3);
        ans -= del;
        std::cout << ans << '\n';
    }

    return 0;
}
// 18 : 00 - 