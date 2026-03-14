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
int c[maxn], p[maxn];
ldb dp[maxn];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            std::cin >> c[i] >> p[i];
        }
        for (int i = 1; i <= n + 1; ++i) {
            dp[i] = 0;
        }
        for (int i = n; i >= 1; --i) {
            dp[i] = std::max(dp[i + 1], dp[i + 1] * (1 - 1.0 * p[i] / 100) + c[i]);
        }
        std::cout << dp[1] << '\n';
    }

    return 0;
}
