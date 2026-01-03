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
#include <iomanip>

#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
const ll mod = 998244353;
int ladder[105];
db dp[105];
int trans(int r, int c) {
    if (r % 2) {
        return (r - 1) * 10 + c - 1;
    } else {
        return (r - 1) * 10 + 10 - c;
    }
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    // std::cin >> T;
    while (T--) {
        for (int i = 1; i <= 10; ++i) {
            for (int j = 1; j <= 10; ++j) {
                int len;
                std::cin >> len;
                int from = trans(i, j);
                int to = trans(i - len, j);
                ladder[from] = to;
            }
        }
        dp[0] = 0;
        for (int i = 1; i <100; ++i) {
            db base = std::min(6, i);
            dp[i] = 6.0 / base;
            for (int j = 1; j <= 6; ++j) {
                if (i < j) break;
               dp[i] += std::min(dp[ladder[i - j]], dp[i - j]) / base;
            }
        }
         std::cout << std::fixed << std::setprecision(10);
        std::cout << dp[100 - 1] << '\n';

    }

    return 0;
}
// 16 : 31 - 17 : 12