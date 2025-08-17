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
const int maxn = 50 + 5;
const ll mod = 998244353;
int n, m;
std::vector<std::string> mp;
int col[2][maxn], row[2][maxn];
int vis[2][maxn];
int comp[maxn][maxn], count;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
pii node[3][2];
void bfs(int i, int j) {
    std::queue<pii> q;
    q.push({i, j});
    comp[i][j] = count;
    node[count][0] = {n + m + 1, 0};
    node[count][1] = {n + m + 1, 0};
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        node[count][0].first = std::min(node[count][0].first, x);
        node[count][0].second = std::max(node[count][0].second, x);
        node[count][1].first = std::min(node[count][1].first, y);
        node[count][1].second = std::max(node[count][1].second, y);
        for (int t = 0; t < 4; ++t) {
            int nx = x + dx[t];
            int ny = y + dy[t];
            if (nx > n || nx < 1) continue;
            if (ny > m || ny < 1) continue;
            if (comp[nx][ny]) continue;
            if (mp[nx][ny] != '#') continue; 
            comp[nx][ny] = count;
            q.push({nx, ny});
        }
    }
}
void fill() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (mp[i][j] == '#') {
                row[0][i] = std::min(row[0][i], j);
                row[1][i] = std::max(row[1][i], j);
                col[0][j] = std::min(col[0][j], i);
                col[1][j] = std::max(col[1][j], i);
            }
        }
    }
    std::queue<pii> q;
    for (int i = 1; i <= n; ++i) {
        if (row[0][i] < row[1][i] - 1) q.push({0, i});
    }
    for (int i = 1; i <= m; ++i) {
        if (col[0][i] < col[1][i] - 1) q.push({1, i});
    }    

    while (!q.empty()) {
        auto [type, i] = q.front(); q.pop();
        vis[type][i] = 0;
        if (type == 0) {
            for (int j = row[0][i] + 1; j <= row[1][i] - 1; ++j) {
                mp[i][j] = '#';
                int pre[2] = {col[0][j], col[1][j]};
                col[0][j] = std::min(col[0][j], i);
                col[1][j] = std::max(col[1][j], i);
                
                if (pre[0] != col[0][j] || col[1][j] != pre[1]) {
                    if (!vis[1][j]) q.push({1, j}), vis[1][j] = 1;
                }
            }
        } else {
            for (int j = col[0][i] + 1; j <= col[1][i] - 1; ++j) {
                mp[j][i] = '#';
                int pre[2] = {col[0][j], col[1][j]};
                row[0][j] = std::min(row[0][j], i);
                row[1][j] = std::max(row[1][j], i);
                if (pre[0] != row[0][j] || row[1][j] != pre[1]) {
                    if (!vis[0][j]) q.push({0, j}), vis[0][j] = 1;
                }
            }
        }
    }
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; std::cin >> T;
    while (T--) {
        std::cin >> n >> m;
        mp.resize(n + 1);
        count = 0;
        for (int i = 1; i <= std::max(n, m); ++i) {
            vis[0][i] = vis[1][i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                comp[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; ++i) {
            std::string x;
            std::cin >> x;
            mp[i] = '.' + x;
        }
        for (int i = 1; i <= m; ++i) {
            col[0][i] = n + 1;
            col[1][i] = 0;
        }
        for (int j = 1; j <= n; ++j) {
            row[0][j] = m + 1;
            row[1][j] = 0;
        }
        fill();

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (!comp[i][j] && mp[i][j] == '#') {
                    ++count;
                    bfs(i, j);
                }
            }
        }
        if (count == 1) {
            // std::cout << ans << '\n';
        } else {
            if (node[1][0].first > node[2][0].first) {
                for (int i = 0; i < 2; ++i) {
                    std::swap(node[1][i], node[2][i]);
                }
            }
            if (node[1][1].first < node[2][1].first) {
                for (int i = node[1][0].second; i <= node[2][0].first; ++i) {
                    mp[i][node[2][1].first] = '#';
                }
                for (int j = node[1][1].second; j <= node[2][1].first; ++j) {
                    mp[node[1][0].second][j] = '#';
                } 
            } else {
                for (int i = node[1][0].second; i <= node[2][0].first; ++i) {
                    mp[i][node[2][1].second] = '#';
                }
                for (int j = node[2][1].second; j <= node[1][1].first; ++j) {
                    mp[node[1][0].second][j] = '#';
                } 
            }
            fill();
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                std::cout << mp[i][j];
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }

    return 0;
}
// 18 : 15 - 20 : 20