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
int dp[51][51][51][51];
int a[51][51];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::string str;
        std::cin >> str;
        for (int j = 1; j <= n; ++j) {
            if (str[j - 1] == '#') a[i][j] = 1;
            else a[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int r = 1; r + i - 1 <= n; ++r) {
                for (int c = 1; c + j - 1 <= n; ++c) {
                    if (i == 1 && j == 1) {
                        dp[r][c][i][j] = a[r][c];
                        continue;
                    }
                    int res = std::max(i, j);
                    if (i >= j) {
                        for (int mid = r; mid < r + i - 1; ++mid) {
                            res = std::min(res, dp[r][c][mid - r + 1][j] + dp[mid + 1][c][r + i - 1 - mid][j]);
                        }
                    } else {
                        for (int mid = c; mid < c + j - 1; ++mid) {
                            res = std::min(res, dp[r][c][i][mid - c + 1] + dp[r][mid + 1][i][c + j - 1 - mid]);
                        }
                    }
                    dp[r][c][i][j] = res;
                }
            }
        }
    }
    std::cout << dp[1][1][n][n] << '\n';

    return 0;
}
// 19 : 42 - 