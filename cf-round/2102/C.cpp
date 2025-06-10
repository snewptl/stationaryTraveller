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
int n;
int mp[505][505];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int vis[505][505];
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
        for (int i = 0; i <= n + 1; ++i) {
            for (int j = 0; j <= n + 1; ++j) {
                vis[i][j] = 1;
            }
        }       
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                vis[i][j] = 0;
            }
        }
        int cur = n * n - 1;
        int dir = 0;
        pii p = {1, 1};
        while (cur != -1) {
            vis[p.first][p.second] = 1;
            mp[p.first][p.second] = cur--;
            pii new_p = {p.first + dx[dir], p.second + dy[dir]};
            if (vis[new_p.first][new_p.second]) {
                dir = (dir + 1) % 4;
                new_p = {p.first + dx[dir], p.second + dy[dir]};
            }
            p = new_p;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) std::cout << mp[i][j] << ' ';
            std::cout << '\n';
        }
    }

    return 0;
}
