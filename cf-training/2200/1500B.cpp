#include <assert.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 5e5 + 5;
const ll mod = 998244353;
int n, m;
ll k;
int a[maxn], b[maxn];
int pos[maxn * 2];
ll first_equal[maxn];
ll Exgcd(ll a, ll b, ll& x, ll& y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    int d = Exgcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        std::cin >> b[i];
        pos[b[i]] = i;
    }
    ll d = std::__gcd(n, m);
    ll lcm = 1ll * n * m / d;
    for (int i = 1; i <= n; ++i) {
        if (!pos[a[i]]) continue;
        if (std::abs(pos[a[i]] - i) % d != 0) continue;
        ll t1, t2;
        Exgcd(n, m, t1, t2);
        ll times = (pos[a[i]] - i) / d;
        t1 *= times;
        t2 *= times;
        t2 = -t2;
        while (std::min(t1, t2) < 0) {
            t1 += m / d;
            t2 += n / d;
        }
        first_equal[i] = 1ll * n * t1 + i; 
    }
    ll l = 1, r = 1e18, ans = 1e18;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        ll equals = 0;
        for (int i = 1; i <= n; ++i) {
            if (!first_equal[i] || mid < first_equal[i]) continue;
            equals += (mid - first_equal[i]) / lcm + 1;
        }
        if (mid - equals >= k) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    std::cout << ans << '\n';
    return 0;
}
/*
a1
*/

// 16 : 10 - 17 : 04