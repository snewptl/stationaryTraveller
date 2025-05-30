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
const int maxn = 1e6 + 5;
const ll mod = 998244353;
std::string a, b;
int count, n;
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
ll val[maxn];
ll ans;
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
        count = 0;
        ans = 0;
        std::cin >> n >> a >> b;
        
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) ++count;
        }
        val[n] = 1;
        for (int i = n - 1; i >= 1; --i) {
            val[i] = ((n - i) * inv(n) % mod * val[i + 1] % mod + 1) * n % mod * inv(i) % mod;
        }
        for (int i = 1; i <= count; ++i) {
            ans += val[i];
            ans %= mod;
        }
        std::cout << ans << '\n';
    }

    return 0;
}
