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
const int maxn = 505;
const ll mod = 998244353;
int n;
ll k;
ll p[maxn];
ll d[maxn];
int q;
ll a[maxn];
bool dp[2][maxn][maxn];
bool vis[2][maxn][maxn];
bool in_stack[2][maxn][maxn];
void dfs(int dir, int i, int j) {
    if (vis[dir][i][j]) return;
    vis[dir][i][j] = 1;
    in_stack[dir][i][j] = 1;
    int new_dir = dir;
    if (j == d[i]) new_dir ^= 1;
    if (new_dir == 0) {
        if (i == 0) dp[dir][i][j] = 1; 
        else {
            int new_j = (p[i] - p[i - 1] + j) % k;
            if (in_stack[new_dir][i - 1][new_j]) dp[dir][i][j] = 0;
            else {
                dfs(new_dir, i - 1, new_j); 
                dp[dir][i][j] = dp[new_dir][i - 1][new_j];
            }
        }
    } else {
        if (i == n) dp[dir][i][j] = 1;
        else {
            int new_j = (p[i + 1] - p[i] + j) % k;
            if (in_stack[new_dir][i + 1][new_j]) dp[dir][i][j] = 0;
            else {
                dfs(new_dir, i + 1, new_j);
                dp[dir][i][j] = dp[new_dir][i + 1][new_j];
            }
        }
    }
    in_stack[dir][i][j] = 0;
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
        std::cin >> n >> k;
        for (int i = 1; i <= n; ++i) std::cin >> p[i];
        for (int i = 1; i <= n; ++i) std::cin >> d[i];
        for (int dir = 0; dir < 2; ++dir) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 0; j < k; ++j) {
                    dp[dir][i][j] = 0;
                    vis[dir][i][j] = in_stack[dir][i][j] = 0;
                }
            }            
        }
        for (int dir = 0; dir < 2; ++dir) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 0; j < k; ++j) {
                    dfs(dir, i, j);
                }
            }            
        }

        std::cin >> q;
        for (int i = 1; i <= q; ++i) {
            std::cin >> a[i];
            auto it = std::lower_bound(p + 1, p + n + 1, a[i]) - p;
            if (it == n + 1) std::cout << "YES\n";
            else {
                int j = (p[it] - a[i]) % k;
                std::cout << (dp[1][it][j] ? "YES\n" : "NO\n");
            }
        }
    }

    return 0;
}
