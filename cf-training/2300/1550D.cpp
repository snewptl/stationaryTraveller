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
    int move_l = 1;
    move_l = std::max(move_l, l - x);
    if (move_l > n) return {0, p[r - l + 1]};
    count[2] += std::min(x * 2, n - move_l + 1);
    move_l += x * 2;
    if (move_l > n) return {0, p[r - l + 1]};
    if (r - x * 2 - l >= 0) {
        count[3] += std::min(r - x * 2 - l + 1, n - move_l + 1);
        move_l += r - l - 2 * x + 1;
    } else {
        move_l += 2 * x - (r - l);
    }
    if (move_l <= n) {
        count[3] = std::min(n - move_l + 1, r - l + 1);
    }
    count[0] = n - (count[1] + count[2] + count[3]);
    if (count[1] + count[3] == 0 || count[2] + count[3] == 0) {
        methods = p[r - l + 1];
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
        methods = p[count[0]];
        if (add % 2) methods *= 2, methods %= 2;
        methods *= C(count[3], min - pre_min), methods %= mod;
        add %= 2;
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
        ll count[4] = {0, 0, 0, 0};
        p[0] = 1;
        for (int i = 1; i <= n; ++i) {
            p[i] = p[i - 1] * (r - l + 1) % mod;
        }
        ll mx = check(1).first;
        if (mx == 0) {
            std::cout << p[r - l + 1] << '\n';
        } else {
            ll le = 1, ri = 1e9, border = 1;
            while (le <= ri) {
                ll mid = (le + ri) / 2;
                pii cur = check(mid);
                if (cur.first == mx) {
                    le = mid + 1;
                    border = mid;
                } else {
                    ri = mid - 1;
                }
            }
            if ()
        }


    }

    return 0;
}
// 21 : 10 - 
/*

i - l 
i - r
*/