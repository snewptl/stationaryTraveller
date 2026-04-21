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
int dp[maxn][3][3]; 
int a[maxn][3];
void update(int i, int up, int dn, int delta) {
    dp[i][up][dn] = std::min(dp[i][up][dn], dp[i - 1][0][0] + delta);
    dp[i][0][dn] = std::min(dp[i][0][dn], dp[i - 1][up][0] + delta);
    dp[i][up][0] = std::min(dp[i][up][0], dp[i - 1][0][dn] + delta);
    dp[i][0][0] = std::min(dp[i][0][0], dp[i - 1][up][dn] + delta);
    if (up == dn) dp[i][0][0] = std::min(dp[i][0][0], dp[i - 1][0][0] + delta);
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= 2; ++i) {
            std::string s;
            std::cin >> s;
            for (int j = 1; j <= n; ++j) {
                if (s[j - 1] == 'B') {
                    a[j][i] = 1;
                } else {
                    a[j][i] = 2;
                }
            }
        }
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    dp[i][j][k] = 1e9;
                }
            }
        }
        dp[0][0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            int up = a[i][1];
            int dn = a[i][2];
            update(i, up, dn, 0);
            update(i, 3 - up, dn, 1);
            update(i, up, 3 - dn, 1);
            update(i, 3 - up, 3 - dn, 2);

        }
        std::cout << dp[n][0][0] << '\n';
    }

    return 0;
}
