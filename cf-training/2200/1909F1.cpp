#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
const ll mod = 998244353;
int n, a[maxn];
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
ll C(int n, int m) {
    if (n < m) return 0;
    return fac[n] * inv(fac[m]) % mod * inv(fac[n - m]) % mod;
}
int solve() {
    ll ans = 1;
    int last = 0;
    for (int i = 1; i <= n; ++i) {
        if (i == n) {
            if (a[n] == -1) a[n] = n;
        }
        if (a[i] == -1) continue;
        if (a[i] > i) return 0;
        int delta = a[i] - a[last];
        if (delta < 0) {
            return 0;
        } else {
            if (delta != 0) {
                ll sum = 0;
                for (int k = 0; k <= delta; ++k) {
                    if (i - last < k) break;
                    if (last - a[last] < k) break;
                    if (i - k - a[last] < delta - k) continue;
                    ll temp = C(i - last, k) * C(last - a[last], k) % mod * fac[k] % mod;
                    temp *= C(i - k - a[last], delta - k) * C(i - last, delta - k) % mod * fac[delta - k] % mod;
                    sum += temp;
                    sum %= mod;
                }
                ans *= sum;
                ans %= mod;
            }
        }
        last = i;
    }
    if (a[n] != n) return 0;
    return ans;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    fac[0] = 1;
    for (int i = 1; i <= 2e5; ++i) fac[i] = fac[i - 1] * i % mod;
    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        std::cout << solve() << '\n';
    }

    return 0;
}