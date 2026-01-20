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
const int lcm = 2520;
int vis[maxn][maxn * 3];
int ranking[maxn][maxn * 3];
int circle[maxn][maxn * 3];
int val[maxn];
int n, q;
int r;
std::vector<std::vector<int>> e;
int modify(int c) {
    return (c % lcm + lcm) % lcm;
}
pii jump(pii start) {
    auto [u, c] = start;
    assert(c >= 0);
    int v = e[u][c % e[u].size()];
    int new_c = modify(c + val[v]);
    return {v, new_c};
}
void dfs(int u, int c) {
    vis[u][c] = r;
    auto [v, new_c] = jump({u, c});
    if (vis[v][new_c]) {
        if (vis[v][new_c] == r) {
            pii start = {v, new_c}, end = {u, c};
            std::set<int> s;
            s.insert(u);
            s.insert(v);
            while(start != end) {
                start = jump(start);
                s.insert(start.first);
            }
            circle[u][c] = s.size();
        } else {
            circle[u][c] = circle[v][new_c];
        }
        return;
    } else {
        ranking[v][new_c] = ranking[u][c] + 1;
        dfs(v, new_c);
        circle[u][c] = circle[v][new_c];
    }
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    // std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            std::cin >> val[i];
        }
        e.clear();
        e.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            int sz;
            std::cin >> sz;
            for (int j = 1; j <= sz; ++j) {
                int v;
                std::cin >> v;
                e[i].push_back(v);
            }
        }
        r = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < lcm; ++j) {
                if (vis[i][j]) continue;
                r += 1;
                ranking[i][j] = 1; 
                dfs(i, j);
            }
        }
        std::cin >> q;
        for (int i = 1; i <= q; ++i) {
            int x, y;
            std::cin >> x >> y;
            std::cout << circle[x][modify(y + val[x])] << '\n';
        }
    }

    return 0;
}
// 16 : 31 - 