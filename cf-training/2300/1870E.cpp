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
const int maxn = 5e3 + 5;
const ll mod = 998244353;
int n, a[maxn], mex[maxn], vis[maxn];
std::vector<std::vector<pii>> vec;
int dp[maxn][maxn * 2];
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
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        for (int i = 1; i <= n + 1; ++i) {
            mex[i] = -1;
        }
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= 2 * n; ++j) {
                dp[i][j] = 0;
            }
        }
        vec.clear();
        vec.resize(n + 1);
        for (int i = n; i >= 1; --i) {
            int cur = 0;
            for (int j = 0; j <= n; ++j) vis[j] = 0;
            for (int j = i; j <= n; ++j) {
                vis[a[j]] = 1;
                while (vis[cur]) ++cur;
                if (mex[j] < cur && (j == i || mex[j - 1] < cur)) {
                    vec[i].push_back({j, cur});
                } 
                mex[j] = cur;
            }    
        }
        dp[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= 2 * n; ++j) {
                if (!dp[i][j]) continue;
                dp[i + 1][j] = 1;
                for (auto [r, seg_mex] : vec[i + 1]) {
                    dp[r][j ^ seg_mex] = 1;
                }
            } 
        }
        for (int i = 2 * n; i >= 0; --i) {
            if (dp[n][i]) {
                std::cout << i << '\n';
                break;
            }
        }
    }

    return 0;
}
// 15 : 09 - 