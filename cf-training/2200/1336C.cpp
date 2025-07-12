#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <assert.h>
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
int trans[maxn][26];
ll dp[maxn][maxn];
std::vector<int> prefix_function(std::string s) {
    int n = (int)s.length();
    std::vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
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
    std::reverse(all(t));
    std::vector<int> vec = prefix_function(t);
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (i == 0) {
                if (t[0] != j + 'a') trans[i][j] = 0;
                else trans[i][j] = 1;
                continue;
            }
            int cur = i;
            if (cur == m) cur = vec[m - 1];
            while (cur && j + 'a' != t[cur]) {
                cur = vec[cur];
            }
            if (j + 'a' != t[cur]) trans[i][j] = cur;
            else trans[i][j] = cur + 1;
        }
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= m; ++j) {
            dp[i + 1][trans[j][s[i] - 'a']] += dp[i][j];
            dp[i + 1][j] = dp[i][j];
            dp[i + 1][trans[j][s[i] - 'a']] %= mod;
            dp[i + 1][j] %= mod;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) ans += dp[i][m], ans %= mod;
    std::cout << ans << '\n';
    return 0;
}
// 15 : 00 - 15 : 45