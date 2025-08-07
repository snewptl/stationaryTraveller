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
const int maxn = 4e5 + 5;
const ll mod = 1e9 + 7;
ll n, k;
ll v[maxn];
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
        std::cin >> n >> k;
        ll divid = n - k;
        for (int i = 1; i <= n; ++i) {
            std::cin >> v[i];
        }
        ll alice = 0, bob = 0;
        for (int i = k + 1; i <= n; ++i) {
            alice += inv(divid) * ((divid + 1) / 2) % mod * v[i];
            bob += inv(divid) * (divid / 2) % mod * v[i];
            alice %= mod;
            bob %= mod;
        }
        ll empty = divid + 1;
        for (int i = 1; i <= k; ++i) {
            alice += inv(empty) * ((empty + 1) / 2) % mod * v[i];
            bob += inv(empty) * (empty / 2) % mod * v[i];
            alice %= mod;
            bob %= mod;
        }
        std::cout << alice << ' ' << bob << '\n';

    }

    return 0;
}
// 16 : 35 - 17 : 02