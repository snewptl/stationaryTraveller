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
const int maxn = 2e5 + 5;
const ll mod = 998244353;
std::string str;
int n;
int dp[2][101][10005];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> str;
    n = str.size();
    int ones = 0;
    for (int i = 0; i < n; ++i) {
        if (str[i] == '1') ones += 1;
    }
    int pairs = ones * (n - ones) / 2;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j <= 100; ++j) {
            for (int k = 0; k <= 10000; ++k) {
                dp[i][j][k] = n + 1;
            }
        }
    }
    dp[0][0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= std::min(i + 1, ones); ++j) {
            for (int k = 0; k <= pairs; ++k) {
                if (j) {
                    int delta = n - i - 1 - (ones - j);
                    if (k >= delta) {
                        dp[1][j][k] = std::min(dp[1][j][k], dp[0][j - 1][k - delta] + (str[i] != '1'));
                    }
                }
                int zeros = n - ones - (i - j);
                if (zeros) {
                    dp[1][j][k] = std::min(dp[1][j][k], dp[0][j][k]);
                }
            }
        }
        for (int j = 0; j <= std::min(i + 1, ones); ++j) {
            for (int k = 0; k <= pairs; ++k)  {
                dp[0][j][k] = dp[1][j][k];
                dp[1][j][k] = n + 1;
            }
        }
    }
    
    std::cout << dp[0][ones][pairs] << '\n';

    return 0;
}