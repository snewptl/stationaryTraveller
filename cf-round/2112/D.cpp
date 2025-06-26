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
int flag;
std::vector<std::vector<int>> e, ans;
int n;

void dfs(int u, int p, int dir) {
    int son = 0;
    for (auto v : e[u]) {
        if (v == p) continue;
        if (e[v].size() == 2) son = v;
    }
    for (auto v : e[u]) {
        if (v == p)continue;
        int cur = dir;
        if (v == son && !flag) cur ^= 1, flag = 1;
        if (!dir) ans[u].push_back(v);
        else ans[v].push_back(u);
        dfs(v, u, cur ^ 1);
    }
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
        flag = 0;
        e.clear();
        e.resize(n + 1);
        ans.clear();
        ans.resize(n + 1);
        for (int i = 1; i < n; ++i) {
            int u, v;
            std::cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        for (int i = 1; i <= n; ++i) {
            if (e[i].size() != 1) continue;
            dfs(i, 0, 0);
            break;
        }
        if (n == 2) flag = 0;
        if (flag) {
            std::cout << "YES\n";
            for (int i = 1; i <= n; ++i) {
                for (auto v : ans[i]) {
                    std::cout << i << " " << v << '\n';
                }
            }
        } else std::cout << "NO\n";

        
    }

    return 0;
}
