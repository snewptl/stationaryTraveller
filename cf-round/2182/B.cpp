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
ll a, b;
pll dp[40];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    dp[1] = {1, 0};
    dp[2] = {1, 2};
    for (int i = 3; i <= 30; ++i) {
        if (i % 2) {
            dp[i] = {dp[i - 1].first + (1 << (i - 1)), dp[i - 1].second};
        } else {
            dp[i] = {dp[i - 1].first, dp[i - 1].second + (1 << (i - 1))};
        }
    }
    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> a >> b;
        int ans = 0;
        for (int i = 1; i <= 30; ++i) {
            if (dp[i].first <= a && dp[i].second <= b) ans = i;
            if (dp[i].first <= b && dp[i].second <= a) ans = i;
        }
        std::cout << ans << '\n';
    }

    return 0;
}
