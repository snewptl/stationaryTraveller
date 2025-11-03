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
const int maxn = 2e4 + 5;
const ll mod = 998244353;
int n, m, k;
int dp[55][maxn], pre[maxn], suf[maxn];
int a[55][maxn];
struct Tree {
    int lazy, mx;
}t[maxn << 2];
int get_sum(int dep, int l, int r) {
    int res = 0;
    for (int i = l; i <= r; ++i) {
        res += a[dep][i];
    }
    return res;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            std::cin >> a[i][j];
        }
    }
    
    int sum = get_sum(n, 1, k);
    for (int i = 1; i + k - 1 <= m; ++i) {
        dp[n][i] = sum;
        sum -= a[n][i];
        sum += a[n][i + k];
    }
    int ans = 0;
    for (int i = n - 1; i >= 1; --i) {
        int sum = get_sum(i, 1, k);
        for (int j = 1; j + k - 1 <= m; ++j) {
            pre[j] = std::max(pre[j - 1], dp[i + 1][j]);
        }
        for (int j = m - k + 1; j >= 1; --j) {
            suf[j] = dp[i + 1][j];
            if (j != m - k + 1) {
                suf[j] = std::max(suf[j + 1], suf[j]);
            }
        }
        int low_sum = get_sum(i + 1, 1, k);
        for (int j = 1; j + k - 1 <= m; ++j) {
            int start = std::max(0, j - k);
            int end = std::min(m + 1, j + k);
            if (start >= 1) dp[i][j] = pre[start];
            if (end <= m) dp[i][j] = std::max(dp[i][j], suf[end]);
            int del = low_sum;
            for (int t = j; t > start; --t) {
                dp[i][j] = std::max(dp[i][j], dp[i + 1][t] - del);
                del -= a[i + 1][t + k - 1];
            }
            del = low_sum - a[i + 1][j];
            for (int t = j + 1; t < end; ++t) {
                dp[i][j] = std::max(dp[i][j], dp[i + 1][t] - del);
                del -= a[i + 1][t];
            }
            dp[i][j] += sum + low_sum;
            sum -= a[i][j];
            sum += a[i][j + k]; 
            low_sum -= a[i + 1][j];
            low_sum += a[i + 1][j + k];
        }
    }
    for (int i = 1; i + k - 1 <= m; ++i) {
        ans = std::max(ans, dp[1][i]);
    }
    std::cout << ans << '\n';
    
    

    return 0;
}
// 20 : 21 - 22 : 03 