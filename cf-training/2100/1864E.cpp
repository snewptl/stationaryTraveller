#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <memory.h>
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
ll dfs(int l, int r, int power, int flag) {
    if (l > r) return 0;
    if (power == 0) return 0;
    auto it = std::lower_bound(a + l, a + r + 1, power);
    int idx = it - a;
    for (int i = idx; i <= r; ++i) {
        a[i] ^= power;
    }
    
    ll temp = (dfs(l, idx - 1, power / 2, flag) + dfs(idx, r, power / 2, 1)) % mod;
    
    ll prem = 3;
    if (flag) prem = 1;
    temp += 1ll * (idx - l) * (r - idx + 1) * prem % mod;

    prem = 2;
    if (flag) prem = 1;
    temp = (temp + 1ll * (r - idx + 1) * (r - idx + 1) * prem % mod) % mod;
    return temp % mod;
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
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        std::sort(a + 1, a + n + 1);
        std::cout << dfs(1, n, 1 << 30, 0) * inv(1ll * n * n % mod) % mod << '\n';
        // std::cout << dfs(1, n, 1 << 30, 0) << '\n';
    }

    return 0;
}
