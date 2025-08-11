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
const int maxn = 1e6 + 5;
const ll mod = 998244353;
int n, c;
std::vector<int> vec;
int link[maxn][2];
int v[maxn];
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
    if (x <= 1e6) {
        return fac[x] * inv(fac[y]) % mod * inv(fac[x - y]) % mod;
    } else {
        ll res = 1;
        for (int i = x, j = y; j >= 1; --j, --i) {
            res *= i, res %= mod;
            res *= inv(j), res %= mod;
        }
        return res;
    }
    
} 

void dfs(int rt) {
    if (link[rt][0] != -1) dfs(link[rt][0]);
    vec.push_back(v[rt]);
    if (link[rt][1] != -1) dfs(link[rt][1]);
} 
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    fac[0] = 1;
    for (int i = 1; i <= 1e6; ++i) {
        fac[i] = fac[i - 1] * i % mod;
    }

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> c;
        vec.clear();
        vec.push_back(1);
        for (int i = 1; i <= n; ++i) {
            int val, l, r;
            std::cin >> l >> r >> val;
            link[i][0] = l;
            link[i][1] = r;
            v[i] = val; 
        }
        dfs(1);
        vec.push_back(c);
        ll ans = 1;
        int l = -1, r = -1, count = 0;
        for (auto it : vec) {
            if (it == -1) ++count;
            else {
                if (l == -1) {
                    l = it;
                } else {
                    r = it;
                    ans *= C(r - l + 1 + count - 1, count);
                    ans %= mod;
                    l = r;
                    r = -1;
                    count = 0;
                }
            }
        }
        std::cout << ans << '\n';
    }

    return 0;
}
// 9 : 05 - 9 : 51