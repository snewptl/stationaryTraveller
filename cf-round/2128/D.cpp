#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <bitset>
#include <memory.h>
#include <assert.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 5e5 + 5;
const ll mod = 998244353;
int n;
int a[maxn];
ll dp[maxn];
ll ans;
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        ans = 1;
        for (int i = 1; i <= n; ++i) dp[i] = 0;
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        dp[1] = 1;
        dp[2] = 2 + (a[2] < a[1]);
        for (int i = 3; i <= n; ++i) {
            if (a[i - 2] > a[i - 1]) {
                if (a[i - 1] > a[i]) {
                    dp[i] = dp[i - 1] + i;
                } else {
                    dp[i] = dp[i - 1] + 1;
                }
            } else {
                if (a[i - 2] > a[i]) {
                    dp[i] = dp[i - 2] + i - 2 + 2 + 1; 
                } else {
                    dp[i] = dp[i - 1] + i;
                }
            }
        }
        for (int i = 2; i <= n; ++i) {
            if (a[i] > a[i - 1]) {
                ans += dp[i - 1] + 1;
            } else {
                ans += dp[i];
            }
        }
        std::cout << ans << '\n';
    }

    return 0;
}
