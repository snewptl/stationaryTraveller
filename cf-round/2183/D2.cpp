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
const int maxn = 2e5 + 5;
const ll mod = 998244353;
std::vector<std::vector<int>> e;
std::vector<std::vector<int>> left_most;
std::vector<std::vector<int>> remain;
std::vector<std::set<int>> opt;
int n;
int fa[maxn];
int given[maxn];
int dep[maxn];
int used[maxn];
int in[maxn];
int max_dep;
void dfs(int u, int p) {
    int son = 0;
    max_dep = std::max(max_dep, dep[u]);
    remain[dep[u]].push_back(u);
    for (auto v : e[u]) {
        if (v == p) continue;
        fa[v] = u;
        if (!son) son = v;
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
    if (son) {
        left_most[dep[son]].push_back(son);
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
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        max_dep = 0;
        e.clear();
        e.resize(n + 1);
        left_most.clear();
        left_most.resize(n + 1);
        remain.clear();
        remain.resize(n + 1);
        opt.clear();
        for (int i = 1; i <= n; ++i) {
            given[i] = 0;
            used[i] = 0;
            in[i] = 0;
        }
        for (int i = 1; i < n; ++i) {
            int u, v;
            std::cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }  
        dfs(1, 0);
        int ans = 0, start = 0;
        for (int i = max_dep; i >= 0; --i) {
            int temp = remain[i].size();
            if (left_most[i].size() <= 1) {
                temp += 1;
            }
            if (ans < temp) {
                ans = temp;
                start = i;
            }
        }
        // std::cout << ans << '\n';
        opt.resize(ans + 1);
        for (int i = 1; i <= ans; ++i) {
            if (i == ans && remain[start].size() < ans) opt[i].insert(fa[remain[start].back()]);
            else opt[i].insert(remain[start][i - 1]);
        }
        for (int i =  ans - 1; i >= 1; --i) {
            for (auto u : remain[i]) {
                int ban = 0;
                for (auto v : e[u]) {
                    if (v == fa[u]) continue;
                    if ()
                }
            }
        }
    }

    return 0;
}
