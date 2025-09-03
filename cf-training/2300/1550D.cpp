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
int n, l, r;
ll p[maxn];
ll fac[maxn];
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
ll C(ll x, ll y) {
    if (y > x) return 0;
    return fac[x] * inv(fac[y]) % mod * inv(fac[x - y]) % mod;
} 
pll check(int x) {
    ll methods = 0, res = 0;
    ll count[4] = {0, 0, 0, 0};
    ll loc1 = r - x, loc2 = l + x;
    if (loc1 < loc2) {
        count[2] = loc1 - 1 + 1;
        count[2] = std::min(n * 1ll, count[2]);
        if (count[2] < n) {
            count[0] = loc2 - loc1 - 1;
            if (count[0] + count[2] >= n) {
                count[0] = n - count[2];
            }
            if (count[0] + count[2] < n) {
                ll fin = loc2 + r - l;
                count[1] = fin - loc2 + 1;
                if (count[1] + count[0] + count[2] >= n) {
                    count[1] = n - count[0] - count[2];
                }
            }
        }
    } else {
        count[2] = std::max(loc2 - 1, 0ll);
        if (count[2] > n) {
            count[2] = n;
        }
        if (count[2] < n) {
            count[3] = loc1 - std::max(1ll, loc2) + 1;
            if (count[3] + count[2] > n) {
                count[3] = n - count[2];
            }
            if (count[2] + count[3] < n) {
                ll fin = loc1 + 2 * x;
                count[1] = fin - loc1;
                if (count[1] + count[2] + count[3] >= n) {
                    count[1] = n - count[2] - count[3];
                }
            }
        }
    }
    if (count[1] + count[3] == 0 || count[2] + count[3] == 0) {
        methods = p[n];
        res = 0;
    } else {
        ll min = std::min(count[1], count[2]);
        ll max = std::max(count[1], count[2]);
        ll pre_min = min;
        ll add = count[3];
        ll temp = std::min(max - min, add);
        add -= temp;
        min += temp;
        min += add / 2;
        max += add / 2;
        add %= 2;
        methods = C(count[3], min - pre_min);
        if (add) methods += C(count[3], min - pre_min + 1);
        methods %= mod;
        methods *= p[count[0]];
        methods %= mod;
        max += add;
        add = 0;
        res = min * max;
    }
    return {res, methods};
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    fac[0] = 1;
    for (int i = 1; i <= 2e5; ++i) {
        fac[i] = fac[i - 1] * i % mod;
    }

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> l >> r;
        p[0] = 1;
        for (int i = 1; i <= n; ++i) {
            p[i] = p[i - 1] * (r - l + 1) % mod;
        }
        ll mx = check(1).first;
        ll le = 1, ri = r - 1, border = 1;
        while (le <= ri) {
            ll mid = (le + ri) / 2;
            pll cur = check(mid);
            if (cur.first == mx) {
                le = mid + 1;
                border = mid;
            } else {
                ri = mid - 1;
            }
        }
        int end = std::max(1ll, border - n);
        ll ans = 0;
        for (int i = border; i >= end; --i) {
            ans += check(i).second;
            ans %= mod;
        }
        ans += check(1).second * (end - 1);
        ans %= mod;
        std::cout << ans << '\n';
        

    }

    return 0;
}
// 21 : 10 - 
/*

i - l 
i - r
*/