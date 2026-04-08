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
int n, k;
std::string s, t;
int pre[maxn];
int nxt[maxn];
int count[2][maxn];
ll fac[maxn];
int vis[maxn];
ll ans = 0;
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
void solve(int sgn) {
    s = t;
    for (int i = 0; i < k - 1; ++i) {
        vis[i] = -1;
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] == '?' || s[i] - '0' == sgn) pre[i] = 1;
        else pre[i] = 0;
        if (i) pre[i] &= pre[i - 1];
    }
    if (pre[n - k]) {
        int sz0 = 0, sz1 = 0;
        for (int i = n - k + 1; i < n; ++i) {
            if (s[i] == '0') sz0 += 1;
            else if (s[i] == '1') sz1 += 1; 
        }
        int remain = k - 1 - sz0 - sz1;
        for (int i = 0; i <= remain; ++i) {
            int need_sgn = sz0;
            int need_inv = sz1;
            if (sgn == 1) std::swap(need_sgn, need_inv);
            need_sgn += i;
            need_inv += remain - i;
            if (need_sgn < need_inv) continue;
            ans += C(remain, i);
            ans %= mod;
        } 
    }
    for (int i = n - 1; i >= n - k + 1; --i) {
        nxt[i] = 1;
        if (s[i] != '?') vis[i % (k - 1)] = s[i] - '0';
    }
    for (int i = n - k; i >= 0; --i) {
        if (vis[i % (k - 1)] == -1) nxt[i] = 1;
        else {
            if (s[i] != '?' && vis[i % (k - 1)] != s[i] - '0') nxt[i] = 0;
            else nxt[i] = 1;
        }
        if (s[i] != '?') vis[i % (k - 1)] = s[i] - '0';
        else {
            if (vis[i % (k - 1)] != -1) s[i] = vis[i % (k - 1)] + '0';
        }
        nxt[i] &= nxt[i + 1]; 
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] == '?') {
            count[0][i] = 0;
            count[1][i] = 0;
        } else {
            count[s[i] - '0'][i] = 1;
            count[(s[i] - '0') ^ 1][i] = 0;
        }
        if (i) {
            count[0][i] += count[0][i - 1];
            count[1][i] += count[1][i - 1];
        }
    }
    for (int i = 0; i <= n - k - 1; ++i) {
        if (!pre[i]) break;
        if (!nxt[i + 1]) continue;
        if (s[i + 1] != '?' && s[i + 1] - '0' != (sgn ^ 1)) continue;
        int sz0 = count[0][i + k - 1] - count[0][i + 1];
        int sz1 = count[1][i + k - 1] - count[1][i + 1];
        int remain = k - 2 - sz0 - sz1;
        int need0 = (k - 1) / 2;
        int need1 = (k - 1) / 2;
        if (sgn == 0) need1 -= 1;
        else need0 -= 1;
        if (need0 < sz0 || need1 < sz1) continue;
        ans += C(remain, need0 - sz0);
        ans %= mod;
    }
    
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
        ans = 0;
        std::cin >> n >> k >> t;
        solve(0);
        solve(1);
        std::cout << ans << '\n';
    }

    return 0;
}
// 18 : 16 - 