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
ll x, y, z, k;
ll cal(ll temp, ll t) {
    if (t % k == 0) {
        --temp;
        temp = std::max(temp, 0LL);
    } 
    return x * t + y * temp + (z - temp * (temp + 1) / 2 * k + t - 1) / t * y;
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
        std::cin >> x >> y >> z >> k; 
        ll ans = 1e18;
        for (ll t = 1; t <= z - 1; t = (z - 1) / ((z - 1) / t) + 1) {
            ll t_min = t, t_max = (z - 1) / ((z - 1) / t);
            ll l = t_min / k, r = t_max / k;
            while (r - l + 1 > 3) { 
                ll m1 = l + (r - l) / 3;
                ll m2 = r - (r - l) / 3;
                ll t1 = std::max(m1 * k, t_min);
                ll t2 = std::max(m2 * k, t_min);
                if (cal(m1, t1) < cal(m2, t2)) {
                    l = m1 + 1;
                } else {
                    r = m2;
                }
            }
            for (ll m1 = l; m1 <= r; ++m1) {
                ll t1 = std::max(m1 * k, t_min);
                ans = std::min(ans, cal(m1, t1));
            }
        }
        ll t = z;
        ll temp = t / k;
        ans = std::min(ans, x * t + y * temp + (z - temp * (temp + 1) / 2 * k + t - 1) / t * y);
        std::cout << ans << '\n';
    }

    return 0;
}
// 10 : 18 - 

/*
temp = (t - 1) / k
x * t1 + y * temp + (z - temp * (temp + 1) / 2 * k + t1 - 1) / t1 * y
*/

// 10 20 30 40 
// 60 60 60 60 40 