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
ll m, d, w;
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
        std::cin >> m >> d >> w;
        ll gcd = std::__gcd(d - 1, w);
        ll x = w / gcd;
        ll i_max = std::min(m, d) - 1;
        ll j_max = std::min(m, d);
        if (!i_max) {
            std::cout << "0\n";
            continue;
        }
        ll pre_count = (j_max - 1) % x + 1;
        ll pre_val = (j_max - 1) / x;
        ll nxt_count = x - (j_max - i_max) % x;
        ll nxt_val = (j_max - i_max) / x;
        ll ans = pre_count * pre_val;
        if (nxt_val != pre_val) ans += nxt_count * nxt_val;
        if (pre_val - 1 >= nxt_val + 1) ans += (pre_val + nxt_val) * (pre_val - nxt_val - 1) / 2 * x;
        std::cout << ans << '\n';
    }

    return 0;
}
// 16 : 05 - 16 : 48
