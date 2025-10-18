#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <queue>
#include <iterator>
#include <array>
#include <numeric>
#include <random>
#include <stack>
#include <unordered_map>

using namespace std;

// #define int long long

using i64 = int64_t;
using pii = pair<int, int>;

// constexpr int MAX_N = 5e3 + 7;
// constexpr int N = 5000;
// constexpr int INF = 2e9;
// constexpr int MOD = 998244353;
// constexpr int base = 233;
// constexpr int p1 = 1e9 + 7;
// constexpr int p2 = 1e9 + 9;

double dp[11][11][11];
int C[11][11];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    C[0][0] = 1;
    for (int i = 1; i <= 10; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
        C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }

    auto calc = [&] (int n, int m) -> double {
        if (m <= 0) return 0;
        if (m >= n) return 1;
        return 1.0 * C[n - 1][m - 1] / C[n][m];
    };

    dp[0][0][0] = 1;
    for (int i = 1; i <= 10; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= i; k++) {
                double p = calc(i, j);
                dp[i][j][k] = (1 - p) * dp[i - 1][j][k];
                if (k > 0) {
                    double now = (1 - p) * dp[i - 1][j][k - 1];
                    if (j > 0) {
                        now += p * dp[i - 1][j - 1][k - 1];
                    }
                    dp[i][j][k] = max(dp[i][j][k], now);
                }
            }
        }
    }

    // for (int i = 0; i <= 4; i++) {
    //     for (int j = 0; j <= i; j++) {
    //         for (int k = 0; k <= i; k++) {
    //             cout << i << " " << j << " " << k << ": " << dp[i][j][k] << endl;
    //         }
    //     }
    // }

    cout << dp[8][4][5] << endl;
    cout << 1.0 * C[5][4] / C[8][4] << endl;
    
    return 0;
}

/*

i cabins, j poisoned, k med
dp[i][j][k] = max 

1. use: p * dp[i - 1][j - 1][k - 1] + (1-p) * dp[i - 1][j][k - 1]
2. not use: p * 0 + (1-p) * dp[i - 1][j][k]

*/