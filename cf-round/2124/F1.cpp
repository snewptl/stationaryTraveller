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
int n, m;
ll dp[105], last[105][105];
int limit[105][105];
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
        std::cin >> n >> m;
        for (int i = 1; i <= n; ++i) dp[i] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                limit[i][j] = 0;
                last[i][j] = 0;
            }
        }
        for (int i = 1; i <= m; ++i) {
            int id, x;
            std::cin >> id >> x;
            limit[id][x] = 1;
        }
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int len = 1; len <= i; ++len) {
                for (int r = 1; r <= len; ++r) {
                    int flag = 1;
                    for (int j = i - len + 1, cur = r; j <= i; ++j, ++cur) {
                        if (cur > len) cur -= len;
                        if (limit[j][cur]) flag = 0;
                    }
                    if (flag) {
                        dp[i] += dp[i - len] - last[i - len][r - 1], dp[i] %= mod;
                        if (r == 1) last[i][len] += dp[i - len] - last[i - len][r - 1], last[i][len] %= mod;
                    }
                }
            }
        }
        std::cout << (dp[n] % mod + mod) % mod<< '\n';
    }

    return 0;
}
