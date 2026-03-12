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
std::vector<std::vector<int> *> loc;
std::vector<std::vector<int>> vec; 
std::vector<std::vector<int>> e;
std::vector<int> res, pos;
int n;
void dfs(int u, int p) {
    int max = 0, son = 0;
    for (auto v : e[u]) {
        if (v == p) continue;
        dfs(v, u);
        if (max < loc[v]->size() || (max == loc[v]->size() && pos[u] > pos[v] + 1)) {
            max = std::max(max, (int)loc[v]->size());
            loc[u] = loc[v];
            son = v;
            res[u] = res[v];
            pos[u] = pos[v] + 1;
        }
    }
    if (!max) {
        loc[u] = &vec[u];
        loc[u]->push_back(1);
        res[u] = 1;
        pos[u] = 0;
    } else {
        for (auto v : e[u]) {
            if (v == p || v == son) continue;
            for (int i = loc[u]->size() - 1, j = loc[v]->size() - 1; j >= 0; --i, --j) {
                (*loc[u])[i] += (*loc[v])[j];
                int newPos = loc[u]->size() - 1 - i + 1;
                if (res[u] < (*loc[u])[i] || (res[u] == (*loc[u])[i] && pos[u] > newPos) ) {
                    res[u] = std::max(res[u], (*loc[u])[i]);
                    pos[u] = newPos;
                }
            }
        }
        loc[u]->push_back(1);
        if (res[u] == 1) {
            pos[u] = 0;
        }
    }
    
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    loc.resize(n + 1);
    e.resize(n + 1);
    vec.resize(n + 1);
    res.resize(n + 1, 0);
    pos.resize(n + 1, 0);
    for (int i = 1; i < n; ++i) {
        int u, v;
        std::cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; ++i) {
        std::cout << pos[i] << '\n';
    }    

    return 0;
}
// 14 : 57 - 