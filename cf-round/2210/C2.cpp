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
const int maxn = 5e4 + 5;
const ll mod = 998244353;
int n;
ll a[maxn], b[maxn], c[maxn];
ll vis[1000000 + 5];
std::vector<ll> vec;
int dp[maxn][51];
ll lcm(ll x, ll y) {
    return x / std::__gcd(x, y) * y;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    vis[1] = 1;
    for (int i = 2; i <= 1e6; ++i) {
        if (!vis[i]) vec.push_back(i);
        for (auto it : vec) {
            if (1ll * it * i > 1e6) break;
            vis[it * i] = 1;
            if (i % it == 0) break;
        }
    }
    vec.resize(50);
    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            c[i] = a[i];
        }
        for (int i = 0; i <= n + 1; ++i) {
            for (int j = 0; j <= 50; ++j) {
                dp[i][j] = -1;
            }
        }
        for (int i = 1; i <= n; ++i) {
            std::cin >> b[i];
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            ll l = 1, r = 1;
            if (i > 1) {
                l = std::__gcd(a[i - 1], a[i]);
            }
            if (i < n) {
                r = std::__gcd(a[i], a[i + 1]);
            }
            ll LCM = lcm(l, r);
            if (LCM <= b[i]) {
                c[i] = LCM;
            }
        }
        c[0] = 1;
        c[n + 1] = 1;
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= 50; ++j) {
                if (dp[i - 1][j] == -1) continue;
                ll ban1 = c[i - 1] / std::__gcd(c[i - 1], c[i]);
                if (j) ban1 *= vec[j - 1];
                ll ban2 = c[i + 1] / std::__gcd(c[i + 1], c[i]);
                if (c[i] != a[i]) dp[i][0] = std::max(dp[i][0], dp[i - 1][j] + 1);
                else {
                    dp[i][0] = std::max(dp[i - 1][j], dp[i][0]);
                    ll fac = b[i] / a[i];
                    for (int k = 0; k < 50; ++k) {
                        if (ban1 % vec[k] == 0 || ban2 % vec[k] == 0) continue;
                        if (fac < vec[k]) break;
                        dp[i][k + 1] = std::max(dp[i][k + 1], dp[i - 1][j] + 1);
                    }
                }
            }
        }
        for (int i = 0; i <= 50; ++i) {
            ans = std::max(ans, dp[n][i]);
        }
        std::cout << ans << '\n';
    }

    return 0;
}