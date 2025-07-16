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
const int maxn = 3e3 + 5;
const ll mod = 998244353;
int n, m;
std::string s, t;
ll dp[2][maxn][maxn];
void dfs(int idx, int l, int flag) {
    if (dp[flag][idx][l] != -1) return;
    dp[flag][idx][l] = 0;
    if (idx == 0) {
        dp[flag][idx][l] = 1;
        return;
    }
    if (l == m) {
        dfs(idx - 1, l, flag);
        dp[flag][idx][l] = dp[flag][idx - 1][l] * 2;
        dp[flag][idx][l] %= mod;
        return;
    }
    if (s[idx - 1] == t[l]) {
        dfs(idx - 1, l + 1, flag);
        dp[flag][idx][l] += dp[flag][idx - 1][l + 1];
        dp[flag][idx][l] %= mod;
    }
    if (!flag && s[idx - 1] == t[l + idx - 1]) {
        assert(l + idx - 1 < m);
        dfs(idx - 1, l, 0);
        dp[flag][idx][l] += dp[0][idx - 1][l];
        dp[flag][idx][l] %= mod;
    } 
    if (flag) {
        int new_flag = (idx - 1) > (m - l);
        dfs(idx - 1, l, new_flag);
        dp[flag][idx][l] += dp[new_flag][idx - 1][l];
        dp[flag][idx][l] %= mod;
    }

}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> s >> t;
    n = s.size();
    m = t.size();
    memset(dp, -1, sizeof(dp));
    ll ans = 0;
    for (int i = m; i <= n; ++i) {
        dfs(i, 0, m != i);
        ans += dp[m != i][i][0];
        ans %= mod;
    }
    std::cout << ans << '\n';
    return 0;
}