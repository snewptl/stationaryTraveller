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
int n, p, k;
struct Person {
    ll a, s[10], rank;
    bool operator < (const Person& x) {
        return a > x.a;
    }
}person[maxn];
const int maxlen = 1 << 7;
const ll inf = 1e18;
ll dp[maxn][maxlen];
int sz[maxlen];
int get_sz(int x) {
    int res = 0;
    for (int i = 0; i < 7; ++i) {
        if ((1 << i) & x) res += 1;
    }
    return res;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> p >> k;
    for (int i = 1; i <= n; ++i) {
        std::cin >> person[i].a;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= p; ++j) {
            std::cin >> person[i].s[j];
        }
    }
    int len = 1 << p;
    for (int i = 0; i < len; ++i) {
        sz[i] = get_sz(i);
    }
    std::sort(person + 1, person + n + 1);

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < len; ++j) {
            dp[i][j] = -inf;
        }
    }
    ll ans = 0;
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < len; ++j) {
            dp[i][j] = std::max(dp[i][j], dp[i - 1][j] + (i - sz[j] > k ? 0 : person[i].a));
            for (int t = 0; t < p; ++t) {
                if (!((1 << t) & j)) continue;
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j ^ (1 << t)] + person[i].s[t + 1]);
            }
            
        }
        if (i >= k + p) ans = std::max(ans, dp[i][len - 1]);
    }
    std::cout << ans << '\n';
 
    

    return 0;
}
// 16 : 22 - 17 : 29 
// 19 : 39 - 20 : 17