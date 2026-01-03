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
ll a[maxn];
ll fac[51];
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
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    fac[0] = 1;
    for (int i = 1; i <= 50; ++i) {
        fac[i] = fac[i - 1] * i % mod;
    }

    int T = 1;
    std::cin >> T;
    while (T--) {
        ll sum = 0, count = 0;
        std::cin >> n;
        std::vector<int> vec;
        for (int i = 0; i <= n; ++i) {
            std::cin >> a[i];
            sum += a[i];
            if (i && a[i]) {
                count += 1; 
                vec.push_back(a[i]);
            }
        }
        ll ans = 0;
        for (ll i = n; i <= n; ++i) {
            ll res = 0;
            std::vector<int> temp;
            temp = vec;
            for (int j = count + 1; j <= i; ++j) temp.push_back(0);
            std::sort(all(temp));
            ll l = sum / i, r = sum / i + 1;
            int flag = 1;
            ll remain = a[0], fixed = 0;
            for (auto &it : temp) {
                if (it <= l) {
                    if (remain < l - it) flag = 0;
                    else remain -= l - it;
                } else if (it == r) {
                    ++fixed;
                } else {
                    flag = 0;
                }
            }
            if (flag) {
                res = C(n - count, i - count) * C(i - fixed, remain) % mod * fac[fixed + remain] % mod * fac[i - fixed - remain] % mod;
            }
            ans = (ans + res) % mod;
        }
        std::cout << ans << '\n';
        
    }

    return 0;
}
