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
int n, m;
std::string s, t;
int dp[405][405][405];
int next[405][26], loc[26];
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
        std::cin >> s >> t;
        n = s.size();
        m = t.size();
        for (int i = 0; i < 26; ++i) loc[i] = n + 1;
        for (int i = n + 1; i >= 0; --i) {
            for (int j = 0; j < 26; ++j) {
                next[i][j] = loc[j];
            }
            if (i <= n && i) loc[s[i - 1] - 'a'] = i;  
        }
        int ans = n + 1;
        for (int len = 0; len <= m; ++len) {
            for (int i = 0; i <= len; ++i) {
                for (int j = len; j <= m; ++j) {
                    if (i == 0 && j == len) {
                        dp[len][i][j] = 0;
                        continue;
                    }
                    dp[len][i][j] = n + 1;
                    if (i) dp[len][i][j] = std::min(dp[len][i][j], next[dp[len][i - 1][j]][t[i - 1] - 'a']);
                    if (j > len) dp[len][i][j] = std::min(dp[len][i][j], next[dp[len][i][j - 1]][t[j - 1] - 'a']);
                }
            }
            ans = std::min(ans, dp[len][len][m]);
        }
        if (ans <= n) std::cout << "YES\n";
        else std::cout << "NO\n";
    }

    return 0;
}
// 15 : 55 - 16 : 33