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
const int maxn = 1e6 + 5;
const ll mod = 1e9 + 7;
int n, m;
int a[maxn];
ll tot = 1;
ll dp[maxn][2];
void solve() {
    if (n % 2) {
        int flag = 1;
        for (int i = 1; i <= n; ++i) {
            if (a[i] != -1 && a[i] != 1) flag = 0;
        }
        tot -= flag;
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] < n && a[i] > 1) return;
    }
    dp[0][1] = 1;
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == -1) {
            if (m >= n) {
                dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod * (m - n + 1) % mod;
                dp[i][0] %= mod;
            }
            dp[i][1] = dp[i - 1][0];
        } else if (a[i] == 1) {
            dp[i][1] = dp[i - 1][0];
            dp[i][0] = 0;
        } else {
            dp[i][1] = 0;
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1], dp[i][0] %= mod;
        }
    }
    tot -= dp[n][0];
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        if (a[i] == -1) tot *= m, tot %= mod;
    }
    solve();
    tot %= mod;
    tot = (tot + mod) % mod;
    std::cout << tot << '\n';

    return 0;
}
