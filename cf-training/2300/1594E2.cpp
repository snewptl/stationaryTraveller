#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <assert.h>
#include <memory.h>
#include <array>
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
ll f[maxn];
int k, n;
std::set<ll, std::greater<ll>> s;
int inv[6] = {1, 0, 3, 2, 5, 4};
std::map<std::string, int> color;
std::map<ll, std::array<ll, 6>> dp;
std::map<ll, int> used;
int depth(ll x) {
    return k - std::__lg(x);
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    color["white"] = 0;
    color["yellow"] = 1;
    color["green"] = 2;
    color["blue"] = 3;
    color["red"] = 4;
    color["orange"] = 5;
    std::cin >> k >> n;
    for (int i = 1; i <= n; ++i) {
        ll x;
        std::string str;
        std::cin >> x >> str;
        s.insert(x);
        std::array<ll, 6> cur;
        for (int j = 0; j < 6; ++j) cur[j] = 0;
        cur[color[str]] = 1;
        dp[x] = cur;
    }
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i <= k; ++i) {
        f[i] = f[i - 1] * 4 % mod * f[i - 1] % mod * 4 % mod;
    }
    ll mul = 1;
    while (!s.empty()) {
        ll u = *s.begin(); s.erase(s.begin());
        if (!used[u * 2]) {
            mul *= f[depth(u)];
            mul %= mod;
        }
        if (u == 1) break;
        ll fa = u / 2;
        std::array<ll, 6> le = dp[u], ri, top;
        if (s.count(u ^ 1)) {
            s.erase(u ^ 1);
            ri = dp[u ^ 1];
            if (!used[(u ^ 1) * 2]) {
                mul *= f[depth(u ^ 1)];
                mul %= mod;
            }
        } else {
            ll temp = f[depth(u ^ 1)];
            for (int i = 0; i < 6; ++i) {
                ri[i] = temp;
            }
        }
        for (int i = 0; i < 6; ++i) {
            ll sum_le = 0, sum_ri = 0;
            for (int j = 0; j < 6; ++j) {
                if (j != i && j != inv[i]) {
                    sum_le += le[j];
                    sum_le %= mod;
                    sum_ri += ri[j];
                    sum_ri %= mod;
                }
            }
            top[i] = sum_le * sum_ri % mod;
        }
        if (!s.count(fa)) {
            for (int i = 0; i < 6; ++i) dp[fa][i] = 1;
            s.insert(fa);
        }
        for (int i = 0; i < 6; ++i) {
            assert((dp[fa][i] == 1) || (dp[fa][i] == 0));
            dp[fa][i] *= top[i];
        }
        used[fa * 2 + 1] = 1;
        used[fa * 2] = 1;
    }
    ll ans = 0;
    for (int i = 0; i < 6; ++i) ans += dp[1][i], ans %= mod;
    ans *= mul;
    ans %= mod;
    std::cout << ans << '\n';
    return 0;
}
// 19 : 10 - 20 : 17