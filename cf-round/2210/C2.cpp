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
ll a[maxn], b[maxn], c[maxn], lcms[maxn];
ll vis[1000000 + 5];
std::vector<ll> vec;
int remain[maxn];
int dp[maxn][1e3];
ll lcm(ll x, ll y) {
    return x / std::__gcd(x, y) * y;
}
std::pair<pii, int> cal(int x) {
    return {{remain[x], std::min(n - x + 1, x)}, x};
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
    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            c[i] = a[i];
        }
        for (int i = 0; i <= n + 1; ++i) {
            remain[i] = 0;
            dp[i][0] = dp[i][1] = dp[i][2] = 0;
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
            lcms[i] = LCM;
        }
        c[0] = 1;
        c[n + 1] = 1;
        std::set<std::pair<pii, int>> s;
        for (int i = 1; i <= n; ++i) {
            ll ban1 = c[i - 1] / std::__gcd(c[i - 1], c[i]);
            ll ban2 = c[i + 1] / std::__gcd(c[i + 1], c[i]);
            if (c[i] != a[i]) {
                ans += 1;
            } else {
                ll fac = b[i] / lcms[i];
                auto pos = std::upper_bound(vec.begin(), vec.end(), fac);
                if (pos == vec.begin()) continue;
                --pos;
                while (pos != vec.begin() && (ban1 % *pos == 0 || ban2 % *pos == 0)) {
                    --pos;
                }
                if ((ban1 % *pos == 0 || ban2 % *pos == 0)) continue;
                remain[i] = pos - vec.begin() + 1;
            }
        }
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = std::max(dp[i - 1][0], std::max(dp[i - 1][1], dp[i - 1][2]));
            if (remain[i]) {
                dp[i][1] = std::max(dp[i - 1][2], dp[i - 1][0]) + 1;
            }
            if (remain[i] > 1) {
                dp[i][2] = std::max(dp[i - 1][1], dp[i - 1][0]) + 1;
            }
        }
        
        std::cout << ans + std::max(std::max(dp[n][0], dp[n][1]), dp[n][2]) << '\n';
    }

    return 0;
}
