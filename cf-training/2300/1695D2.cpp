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
int n;
std::vector<std::vector<int>> e;
int have[maxn], need[maxn];
int ans;
void dfs(int u, int p) {
    int sz = 0, count = 0;
    for (auto v : e[u]) {
        if (v == p) continue;
        dfs(v, u);
        if (!have[v]) ++sz;
        else count += 1;
        need[u] |= need[v];
        have[u] |= have[v];
    }
    if (sz > 1) ans += sz - 1, have[u] = 1;
    if (count == 0) {
        if (sz > 1) need[u] = 1;
        else if (u == 1 && sz == 1) ans += 1;
    } else if (count == 1) {
        if (u == 1 && need[u]) {
            if (sz <= 1) ans += 1;
        }
        if (sz >= 1) need[u] = 1;
    } else if (count >= 2) {
        
        need[u] = 0;
        if (sz >= 1) need[u] = 1;  
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
        e.clear();
        e.resize(n + 1);
        ans = 0;
        for (int i = 1; i <= n; ++i) {
            have[i] = 0;
            need[i] = 0;
        }
        for (int i = 1; i < n; ++i) {
            int u, v;
            std::cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(1, 0);
        std::cout << ans << '\n';
    }

    return 0;
}
// 21 : 10 - 22 : 40 