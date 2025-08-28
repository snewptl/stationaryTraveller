#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <bitset>
#include <memory.h>
#include <assert.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
const ll mod = 998244353;
std::vector<std::vector<int>> e;
int n;
int dis[maxn], vis[maxn];
int rt[2];
int dfs(int u, int p) {
    int son = 0;
    for (auto v : e[u]) {
        if (v == p) continue;
        dis[v] = dis[u] + 1;
        int cur = dfs(v, u);
        if (!son || dis[son] < dis[cur]) {
            son = cur;
        }
    }
    if (!son) return u;
    return son;
}
void solve() {
    int cur = rt[1];
    while (cur != rt[0]) {
        int flag = 0;
        vis[cur] = 1;
        if (e[cur].size() >= 3) {
            int from, to, mid;
            for (auto v : e[cur]) {
                if (dis[v] == dis[cur] - 1) to = v;
                else if (vis[v]) from = v;
                else mid = v;
            }
            std::cout << from << ' ' << cur << ' ' << mid << '\n'; 
            return;
        }
        for (auto v : e[cur]) {
            if (dis[v] == dis[cur] - 1) {
                cur = v;
                break;
            }
        }
    }
    std::cout << "-1\n";
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
        e.clear();
        e.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            vis[i] = 0;
        }
        for (int i = 1; i < n; ++i) {
            int u, v;
            std::cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dis[1] = 0;
        rt[0] = dfs(1, 0);
        dis[rt[0]] = 0;
        rt[1] = dfs(rt[0], 0);
        solve();

    }

    return 0;
}
