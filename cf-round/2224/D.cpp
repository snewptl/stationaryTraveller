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
const int maxn = 2e3 + 5;
const ll mod = 998244353;
int n;
ll a[maxn], b[maxn];
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
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    fac[0] = 1;
    for (int i = 1; i <= 2e3; ++i) {
        fac[i] = fac[i - 1] * i % mod;
    }
    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            std::cin >> b[i];
        }
        auto mysort = [](const std::pair<pll, int> &a, const std::pair<pll, int>& b) {
            if (a.first.first * b.first.second == a.first.second * b.first.first) {
                return a.second < b.second;
            }
            return a.first.first * b.first.second < a.first.second * b.first.first;
        };
        std::vector<std::pair<pll, int>> vec;
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                vec.push_back({{a[i], a[j]}, (i - 1) * n + j - 1});
            }
        } 
        std::sort(all(vec), mysort);
        ll invn =  inv(n * (n - 1));
        ll ans = 0;
        std::vector<std::pair<pll, int>> now;
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                now.push_back({{b[j], b[i]}, n * (n + 1)});
                now.push_back({{b[i], b[j]}, n * (n + 1)});
            }
        } 
        std::sort(all(now), mysort);
        int pos = 0;
        for (auto [dn, _] : now) {
            while (pos < vec.size()) {
                auto [up, _] = vec[pos];
                if (up.first * dn.second <= up.second * dn.first) ++pos;
                else break;
            }
            ans += invn * ((int)vec.size() - pos);
            ans %= mod;
        }
        std::cout << ans << '\n';
    }

    return 0;
}
