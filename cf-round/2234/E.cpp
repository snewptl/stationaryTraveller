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
const int maxn = 5e5 + 5;
const ll mod = 1e9 + 7;
int n;
ll a[maxn], b[maxn];
pll t[maxn << 2];
ll fac[maxn];
int flag = 1;
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

void build(int rt, int l, int r) {
    if (l == r) {
        t[rt] = {l, 1};
        return;
    }
    int mid = (l + r) / 2;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    if (a[t[rt << 1].first] < a[t[rt << 1 | 1].first]) t[rt] = t[rt << 1 | 1];
    else if (a[t[rt << 1].first] == a[t[rt << 1 | 1].first]) t[rt] = t[rt << 1], t[rt].second += t[rt << 1 | 1].second;
    else t[rt] = t[rt << 1];

}
pll query(int rt, int l, int r, int xl, int xr) {
    if (xl == l && xr == r) {
        return t[rt];
    }
    int mid = (l + r) / 2;
    pll resl = {0, 0}, resr = {0, 0};
    if (xl <= mid) resl = query(rt << 1, l, mid, xl, std::min(xr, mid));
    if (xr > mid) resr = query(rt << 1 | 1, mid + 1, r, std::max(mid + 1, xl), xr);
    if (!resl.first) return resr;
    if (!resr.first) return resl;
    if (a[resl.first] < a[resr.first]) return resr;
    else if (a[resl.first] == a[resr.first]) {
        return {resl.first, resl.second + resr.second};
    } else {
        return resl;
    }
}
ll solve(int l, int r) {
    if (l >= r) return 1;
    pll res = query(1, 1, n, l, r);
    if (res.second > 1) return 0;
    ll mul_l = res.first - l + 1, mul_r = r - res.first + 1;
    if (mul_l * mul_r != a[res.first]) return 0;
    ll ans_l = solve(l, res.first - 1);
    ll ans_r = solve(res.first + 1, r);
    return ans_l * ans_r % mod * C(r - l, res.first - l) % mod;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    fac[0] = 1;
    for (int i = 1; i <= 5e5; ++i) {
        fac[i] = fac[i - 1] * i % mod;
    }

    int T = 1;
    std::cin >> T;
    while (T--) {
        flag = 1;
        std::cin >> n;
        ll sum = 0;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            sum += a[i];
        }
        if (sum >= n * (n + 1) / 2) {
            std::cout << "0\n";
            continue;
        } else {
            for (int i = 1; i <= n; ++i) {
                for (int j = 2; j * j <= a[i]; ++j) {
                    if (a[i] % j == 0) b[i] = j;
                }
                b[]
            }
            build(1, 1, n);
            std::cout << solve(1, n) << '\n';

        }
    }

    return 0;
}
