#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const ll mod = 1e9 + 7;
const int maxn = 2e5 + 5;
ll fac[maxn];
ll quickPow(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y & 1)
            res *= x, res %= mod;
        x *= x, x %= mod;
        y /= 2;
    }
    return res;
}
ll inv(ll x) {
    return quickPow(x, mod - 2);
}
ll C(ll up, ll down) {
    return fac[down] * inv(fac[up]) % mod * inv(fac[down - up]) % mod;
}
int m1, m2, n;
int p[maxn], s[maxn];
void solve() {
    if (p[m1] != s[1]) {
        std::cout << "0\n";
        return; 
    } 
    if (p[1] != 1 || s[m2] != n) {
        std::cout << "0\n";
        return; 
    }

    ll ans = C(p[m1] - 1, n - 1);
    for (int i = m1; i > 1; --i) {
        ans *= C(p[i] - p[i - 1] - 1, p[i] - 2) * fac[p[i] - p[i - 1] - 1] % mod;
        ans %= mod;
    }

    for (int i = 1; i < m2; ++i) {
        ans *= C(s[i + 1] - s[i] - 1, n - s[i] - 1) * fac[s[i + 1] - s[i] - 1] % mod;
        ans %= mod;
    }
    std::cout << ans << '\n';
}
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    fac[0] = 1;
    for (int i = 1; i < maxn; ++i)
        fac[i] = fac[i - 1] * i, fac[i] %= mod;
    while (T--) {
        std::cin >> n >> m1 >> m2;
        for (int i = 1; i <= m1; ++i) std::cin >> p[i];
        for (int i = 1; i <= m2; ++i) std::cin >> s[i];
        solve();
    }

    return 0;
}
