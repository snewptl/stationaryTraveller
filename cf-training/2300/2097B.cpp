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
const ll mod = 1e9 + 7;
int n, m, k;
int vis[maxn][maxn];
int top[maxn][maxn], bottom[maxn][maxn];
pii a[maxn * maxn];
bool is_same_row(pii x, pii y) {
    return x.first == y.first && abs(x.second - y.second) == 2;
}
bool is_same_col(pii x, pii y) {
    return x.second == y.second && abs(x.first - y.first) == 2;
}
bool is_top_left(pii x, pii y) {
    return x.first == y.first - 1 && x.second == y.second - 1;
}
bool is_bottom_left(pii x, pii y) {
    return x.first == y.first + 1 && x.second == y.second - 1;
}
void solve() {
    ll ans = 1;
    int flag = 1;
    for (int i = 1; i <= k; ++i) {
        pii x = a[i], y = a[i + 1];
        if (x.second > y.second) std::swap(x, y);
        if (is_same_row(x, y)) {
            if (vis[x.first][x.second + 1]) flag = 0;
            vis[x.first][x.second + 1] = 1;
        } else if (is_same_col(x, y)) {
            if (vis[(x.first + y.first) / 2][x.second]) flag = 0;
            vis[(x.first + y.first) / 2][x.second] = 1;
        } else if (is_top_left(x, y)) {
            top[x.first][x.second] = 1;
        } else if (is_bottom_left(x, y)) {
            bottom[x.first][x.second] = 1;
        } else {
            flag = 0;
        }
    }
    for (int i = 2; i <= n + m; ++i) {
        int row = std::max(1, i - m), col = i - row;
        if (!top[row][col]) continue;
        int count = 1, obstacle = vis[row][col + 1] + vis[row + 1][col];
        while (row + 1 <= n && col - 1 >= 1) {
            if (!top[row][col]) break;
            ++count;
            obstacle += vis[row + 1][col];
        }
        if (obstacle >= 2) flag = 0;
        else if (!obstacle) ans *= count + 1, ans %= mod;
    }
    for (int i = -m; i <= )
    
    std::cout << (flag ? ans : 0) << '\n';
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
        std::cin >> n >> m >> k;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1;j <= m; ++j) {
                vis[i][j] = 0;
                top[i][j] = 0;
                bottom[i][j] = 0;
            }
        }
        for (int i = 1; i <= k + 1; i += 1) {
            std::cin >> a[i].first >> a[i].second;
            vis[a[i].first][a[i].second] = 1;
        }
        solve();
    }

    return 0;
}
// 21 : 43 - 22 : 30