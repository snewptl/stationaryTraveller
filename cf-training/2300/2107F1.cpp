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
const int maxn = 5e3 + 5;
const ll mod = 998244353;
const ll inf = 1e18;
int n;
ll a[maxn];
ll dp[maxn];
void dfs(int l) {
    if (dp[l] != inf) return;
    if (l > n) {
        dp[l] = 0;
        return;
    }
    ll mn = 1e9 + 1;
    int pos = l;
    for (int i = l; i <= n; ++i) {
        if (mn > a[i]) {
            mn = a[i];
            pos = i;
        }
    }
    ll res = mn * (pos - l + 1) + pos - l;
    for (int i = pos; i <= n; ++i) {
        dfs(i + 1);
        dp[l] = std::min(dp[l], res + dp[i + 1] + a[pos] * (i - pos) + 2 * (i - pos));
    }
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
        std::cin >> n;
        for (int i = 0; i <= n + 1; ++i) dp[i] = inf;
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        dfs(1);
        std::cout << dp[1] << '\n';
    }

    return 0;
}
// 21 : 08 - 21 : 37