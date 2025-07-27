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
pii a[maxn * maxn];
int dx[4] = {1, 1, -1, -1};
int dy[4] = {1, -1, -1, 1};
int counted[maxn][maxn], dir[4][maxn][maxn], in_queue[4][maxn][maxn];
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
            dir[0][x.first][x.second] = 1;
            dir[2][x.first + 1][x.second + 1] = 1;
        } else if (is_bottom_left(x, y)) {
            dir[3][x.first][x.second] = 1;
            dir[1][x.first - 1][x.second + 1] = 1;
        } else {
            flag = 0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1;j <= m; ++j) {
            counted[i][j] = vis[i][j];
        }
    }
    for (int k = 0; k < 4; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (!dir[k][i][j]) continue;
                if (in_queue[k][i][j]) continue;
                in_queue[k][i][j] = 1;
                in_queue[k ^ 2][i + dx[k]][j + dy[k]] = 1;
                int add_equal = 2;
                std::queue<std::pair<int, pii>> q;
                q.push({k, {i, j}});
                int q_size = 0, empty_size = 0;
                while (!q.empty()) {
                    auto [type, pos] = q.front(); q.pop();
                    auto [x, y] = pos;
                    int turn[2] = {(type - 1 + 4) % 4, (type + 1) % 4};
                    ++q_size;
                    if (!counted[x + dx[type]][y]) {
                        counted[x + dx[type]][y] = 1;
                        ++empty_size;
                    }
                    if (!counted[x][y + dy[type]]) {
                        counted[x][y + dy[type]] = 1;
                        ++empty_size;
                    }
                    if (vis[x + dx[type]][y] || vis[x][y + dy[type]]) add_equal = 1;
                    for (int tn = 0; tn < 2; ++ tn) {
                        int cur = turn[tn];
                        if (!in_queue[type][x + dx[cur]][y + dy[cur]] && dir[type][x + dx[cur]][y + dy[cur]]) {
                            in_queue[type][x + dx[cur]][y + dy[cur]] = 1;
                            in_queue[type ^ 2][x + dx[cur] + dx[type]][y + dy[cur] + dy[type]] = 1;
                            q.push({type, {x + dx[cur], y + dy[cur]}});
                            // ++q_size;
                            // if (!counted[x + dx[cur] + dx[type]][y + dy[cur]]) {
                            //     counted[x + dx[cur] + dx[type]][y + dy[cur]] = 1;
                            //     ++empty_size;
                            // }
                            // if (!counted[x + dx[cur]][y + dy[cur] + dy[type]]) {
                            //    counted[x + dx[cur]][y + dy[cur] + dy[type]] = 1;
                            //    ++empty_size;
                            // }
                        }
                        if (!in_queue[cur][x][y] && dir[cur][x][y]) {
                            in_queue[cur][x][y] = 1;
                            in_queue[cur ^ 2][x + dx[cur]][y + dy[cur]] = 1;
                            q.push({cur, {x, y}});
                            // ++q_size;
                            // if (!counted[x + dx[cur]][y]) {
                            //     counted[x + dx[cur]][y] = 1;
                            //     ++empty_size;
                            // }
                            // if (!counted[x][y + dy[cur]]) {
                            //     counted[x][y + dy[cur]] = 1;
                            //     ++empty_size;
                            // }
                        }
                        if (!in_queue[cur][x + dx[type]][y + dy[type]] && dir[cur][x + dx[type]][y + dy[type]]) {
                            in_queue[cur][x + dx[type]][y + dy[type]] = 1;
                            in_queue[cur ^ 2][x + dx[type] + dx[cur]][y + dy[type] + dy[cur]] = 1;
                            q.push({cur, {x + dx[type], y + dy[type]}});
                            // ++q_size;
                            // if (!counted[x + dx[type] + dx[cur]][y + dy[type]]) {
                            //     counted[x + dx[type] + dx[cur]][y + dy[type]] = 1;
                            //     ++empty_size;
                            // }
                            // if (!counted[x + dx[type]][y + dy[type] + dy[cur]]) {
                            //     counted[x + dx[type]][y + dy[type] + dy[cur]] = 1;
                            //     ++empty_size;
                            // }
                        }
                    }
                }
                if (q_size > empty_size) flag = 0;
                else if (empty_size == q_size) ans *= add_equal, ans %= mod;
                else if (empty_size > q_size) {
                    ans *= empty_size;
                    ans %= mod;
                    assert(empty_size == q_size + 1);
                }
            }
        }
    }
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
        for (int i = 1; i <= n + 1; ++i) {
            for (int j = 1; j <= m + 1; ++j) {
                vis[i][j] = 0;
                counted[i][j] = 0;
                for (int k = 0; k < 4; ++k) {
                    dir[k][i][j] = 0;
                    in_queue[k][i][j] = 0;
                } 
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
// 14 : 00 - 16 : 30