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
int n, k;
pii dp[365][365];
int a[maxn];
int next[maxn][365];
int pos[365];
int ans;
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
        std::cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        for (int i = 0; i <= k; ++i) {
            pos[i] = n + 1;
        }
        for (int i = n; i >= 0; --i) {
            for (int j = 0; j <= k; ++j) {
                next[i][j] = pos[j];
            }
            for (int j = 0; j <= a[i]; ++j) {
                pos[j] = i;
            }
            
        }
        for (int i = 0; i <= k; ++i) {
            for (int j = 0; j <= k; ++j) {
                dp[i][j] = {n + 1, 0};
            }
        }
        ans = 0;
        dp[0][k] = {0, 0};
        for (int i = 0; i < k; ++i) {
            for (int j = i + 1; j <= k; ++j) {
                if (dp[i][j].first == n + 1) continue;
                for (int new_i = i + 1; new_i <= j; ++new_i) {
                    int new_j = j - new_i;
                    int new_pos = next[dp[i][j].first][new_i];
                    if (new_pos == n + 1) continue; 
                    int new_val = dp[i][j].second + (n - new_pos + 1) * (new_i - i);
                    if (new_pos < dp[new_i][new_j].first) {
                        dp[new_i][new_j] = {new_pos, new_val};
                    } else if (new_pos == dp[new_i][new_j].first) {
                        dp[new_i][new_j].second = std::max(dp[new_i][new_j].second, new_val);
                    }
                }
            }
        }
        for (int i = 0; i <= k; ++i) {
            for (int j = 0; j <= k; ++j) {
                if (dp[i][j].first != n + 1) {
                    ans = std::max(ans, dp[i][j].second);
                }
            }
        }
        std::cout << ans << '\n';
        
    }

    return 0;
}
