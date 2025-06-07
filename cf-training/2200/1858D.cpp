// 15 : 45
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
const int maxn = 3e3 + 5;
const ll mod = 998244353;
int n, k;
std::string str;
int res[maxn];
int sum[maxn];
int pre[maxn][maxn], next[maxn][maxn];
void solve() {
    for (int i = 0; i <= n + 1; ++i) res[i] = -1;
    for (int i = 0; i <= k; ++i) {
        for (int start = 1; start <= n; ++start) {
            int l = 1, r = n - start + 1, max_len = 0;
            while(l <= r) {
                int mid = l + r >> 1;
                int flag = 0;
                if (sum[start + mid - 1] - sum[start - 1] + i >= mid) flag = 1;
                if (flag) max_len = mid, l = mid + 1;
                else r = mid - 1;
            }
            res[max_len] = std::max(res[max_len], std::max(pre[start - 1][k - i], next[start + max_len][k - i]));
        }
    }
    for (int j = 1; j <= n; ++j) {
        int ans = 0;
        for (int i = 0; i <= n; ++i) {
            if (res[i] == -1) continue;
            ans = std::max(ans, res[i] + i * j);
        }
        std::cout << ans << ' ';
    }
    std::cout << '\n';

}
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
        std::cin >> n >> k >> str;
        str.resize(n + 1);
        for (int i = n; i >= 1; --i) str[i] = str[i - 1];
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i - 1] + (str[i] == '0');
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                if (str[i] == '1') pre[i][j] = pre[i - 1][j] + 1;
                else {
                    if (!j) pre[i][j] = 0;
                    else pre[i][j] = pre[i - 1][j - 1] + 1;
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                pre[i][j] = std::max(pre[i][j], pre[i - 1][j]);
            }
        }
        for (int i = n + 1; i >= 1; --i) {
            for (int j = 0; j <= k; ++j) {
                if (i == n + 1) {
                    next[i][j] = 0;
                    continue;
                }
                if (str[i] == '1') next[i][j] = next[i + 1][j] + 1;
                else {
                    if (!j) next[i][j] = 0;
                    else next[i][j] = next[i + 1][j - 1] + 1;
                }
            }
        }
        for (int i = n; i >= 1; --i) {
            for (int j = 0; j <= k; ++j) {
                next[i][j] = std::max(next[i][j], next[i + 1][j]);
            }
        }
        solve();
    }

    return 0;
}
// 17 : 00

// 
