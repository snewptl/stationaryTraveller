#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
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
int n, k;
int a[maxn];
int dp[maxn];
bool check(int x) {
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        if ((i - 1) % k == 0) {
            if (i > k) dp[i] = std::max(dp[i - k], 1 * (a[i] >= x));
            else dp[i] = 1 * (a[i] >= x);
        } else {
            dp[i] = dp[i - 1] + (a[i] >= x);
            if (i > k) dp[i] = std::max(dp[i], dp[i - k]);
        }
        if ((i - 1) % k + 1 == (n - 1) % k + 1) res = std::max(res, dp[i]);
    }
    int count = (n - 1) % k + 1;
    return res >= count - ((count + 1) / 2 - 1);
}
void solve() {
    int l = 1, r = 1e9, ans = 0;
    while(l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    std::cout << ans << '\n';
}
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
        std::cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        solve();
    }

    return 0;
}
