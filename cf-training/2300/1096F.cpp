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
int n;
int a[maxn];
int suffix[maxn];
ll ans;
ll qp(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y & 1) res *= x, res %= mod;
        x *= x, x %= mod;
        y /= 2;
    }
    return res;
}
ll inv(ll x) {
    return qp(x, mod - 2);
}
int lowbit(int x) {
    return x & (-x);
}
int fw[maxn];
void update(int x, int delta) {
    while (x <= n) {
        fw[x] += delta;
        x += lowbit(x);
    }
}
int query(int x) {
    int res = 0;
    while (x) {
        res += fw[x];
        x -= lowbit(x);
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

    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    ll count = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] != -1) suffix[a[i]] = 1;
    }
    for (int i = n - 1; i >= 1; --i) {
        suffix[i] += suffix[i + 1];
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] == -1) {
            count += 1;
        } else {
            ll res = query(n) - query(a[i]);
            ll remain = n - a[i] - suffix[a[i] + 1];
            ans += res;
            ans %= mod;
            ans += remain * count % mod * inv(n - suffix[1]) % mod;
            ans %= mod;
            remain = a[i] - (suffix[1] - suffix[a[i] + 1]);
            ans += remain * (n - suffix[1] - count) % mod * inv(n - suffix[1]) % mod;
            update(a[i], 1);
        }
    }
    ans += count * (count - 1) / 2 % mod * inv(2) % mod;
    ans %= mod; 
    std::cout << ans << '\n';
    

    return 0;
}