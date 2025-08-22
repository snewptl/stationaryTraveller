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
const int maxn = 1e3 + 5;
const ll mod = 998244353;
int n;
int a[maxn][maxn], mp[maxn][maxn];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
bool is_out(int x) {
    if (x < 1 || x > n) return true;
    return false;
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
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                std::cin >> mp[i][j];
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                a[i][j] = -1;
            }
        }
        for (int i = 1; i <= n; ++i) {
            a[1][i] = 1;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= n; ++j) {
                int count = 0;
                for (int t = 0; t < 4; ++t) {
                    int ni = dx[t] + i;
                    int nj = dy[t] + j;
                    if (is_out(ni) || is_out(nj)) continue;
                    if (ni > i) continue;
                    count ^= a[ni][nj];
                } 
                a[i + 1][j] = count ^ 1;
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (a[i][j]) {
                    ans ^= mp[i][j];
                }
            }
        }
        std::cout << ans << '\n';
    }

    return 0;
}
// 10 : 51 - 12 : 15