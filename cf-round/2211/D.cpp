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
int n;
ll b[maxn];
ll ans[maxn];
int count[31];
std::vector<pii> vec;
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

int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    fac[0] = 1;
    for (int i = 1; i <= 1e5; ++i) {
        fac[i] = fac[i - 1] * i % mod;
    }

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        vec.clear();
        for (int i = 1; i <= n; ++i) {
            ans[i] = 0;
        }
        for (int i = 0; i < 30; ++i) {
            count[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            std::cin >> b[i];
        }
        if (b[n]) {
            vec.push_back({b[n], n});
        }
        for (int i = n - 1; i >= 1; --i) {
            for (auto [val, size] : vec) {
                b[i] -= C(size, i) * val % mod;
                b[i] = (b[i] % mod + mod) % mod;
            }
            if (b[i]) vec.push_back({b[i], i});
        }
        for (auto [val, size] : vec) {
            for (int j = 0; j < 30; ++j) {
                if (val & (1 << j)) count[j] += size;
            }
        }
        for (int i = 0; i < 30; ++i) {
            int cur = 1 << i;
            for (int j = 1; j <= count[i]; ++j) {
                ans[j] += cur;
            }
        }
        for (int i = 1; i <= n; ++i) {
            std::cout << ans[i] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
