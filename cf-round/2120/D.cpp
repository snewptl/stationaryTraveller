#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <bitset>
#include <memory.h>
#include <assert.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
const ll mod = 1e9 + 7;
ll a, b, k;
ll quick_pow(ll x, ll y) {
    x %= mod;
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
        std::cin >> a >> b >> k;
        ll row = (k * (a - 1) + 1) % mod;
        ll cal = k * (b - 1) % mod;
        for (int i = 1; i <= a; ++i) {
            cal *= inv(i);
            cal %= mod;
            cal *= (row - i + 1 + mod) % mod;
            cal %= mod;
        }
        cal += 1;
        cal %= mod;
        row %= mod;
        std::cout << row << ' ' << cal << '\n';
    }

    return 0;
}
