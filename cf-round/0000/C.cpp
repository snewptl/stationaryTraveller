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
int n, m, k;
int sum[505][505], mp[505][505];
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
        std::cin >> n >> m >> k;
        for (int i = 1; i <= n; ++i) {
            std::string str;
            std::cin >> str;
            for (int j = 0; j < m; ++j) {
                if (str[j] == '.') mp[i][j + 1] = 0;
                else if (str[j] == '#') mp[i][j + 1] = 1;
                else mp[i][j + 1] = 2;
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
                sum[i][j] += mp[i][j] == 2;
            }
        }
        
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (mp[i][j] != 0) continue;
                pii end = {std::min(n, i + k - 1), std::min(m, j + k - 1)};
                pii start = {std::max(1, i - k + 1), std::max(1, j - k + 1)};
                int temp = sum[end.first][end.second] - sum[end.first][start.second - 1] - sum[start.first - 1][end.second] + sum[start.first - 1][start.second - 1];
                ans = std::max(ans, sum[n][m] - temp);
            }
        }
        std::cout << ans << '\n';
    }

    return 0;
}
