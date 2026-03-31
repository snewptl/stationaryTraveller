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
<<<<<<< HEAD
ll a[maxn], b[maxn], c[maxn];
ll vis[1000000 + 5];
std::vector<ll> vec;
int dp[maxn][51];
ll lcm(ll x, ll y) {
    return x / std::__gcd(x, y) * y;
}
=======
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
>>>>>>> 33881cd33f7faea7c29e55e4b113180466582591
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
<<<<<<< HEAD
    vec.resize(50);
=======
>>>>>>> 33881cd33f7faea7c29e55e4b113180466582591
    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            c[i] = a[i];
        }
        for (int i = 0; i <= n + 1; ++i) {
<<<<<<< HEAD
            for (int j = 0; j <= 50; ++j) {
                dp[i][j] = -1;
            }
=======
            remain[i] = 0;
            dp[i][0] = dp[i][1] = dp[i][2] = 0;
>>>>>>> 33881cd33f7faea7c29e55e4b113180466582591
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
<<<<<<< HEAD
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
=======
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
>>>>>>> 33881cd33f7faea7c29e55e4b113180466582591
