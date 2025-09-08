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
std::vector<std::vector<int>> e;
int dp[maxn], flag;
void dfs(int u, int p, int bound) {
    dp[u] = 0;
    int exceed = 0, min = n;
    for (auto v : e[u]) {
        if (v == p) continue;
        dfs(v, u, bound);
        if (dp[v] + 2 > bound) {
            if (exceed) flag = 0;
            else exceed = dp[v] + 1;
        }
        min = std::min(min, dp[v] + 1);
    }
    if (exceed) {
        dp[u] = exceed;
    } else {
        if (min != n) dp[u] = min;
    }
}
int check(int x) {
    flag = 1;
    dfs(1, 0, x);
    if (dp[1] > x) flag = 0;
    return flag;
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
        e.clear();
        e.resize(n + 1);
        for (int i = 1; i < n; ++i) {
            int u, v;
            std::cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        // std::cout << check(1) << '\n';
        int l = 1, r = n, ans = n;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(mid)) {
                r = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }
        std::cout << ans << '\n';
    }

    return 0;
}
// 17 : 44 - 18 : 23