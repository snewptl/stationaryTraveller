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
std::vector<std::vector<int>> e;
int a[maxn];
void dfs(int u, int p, int sgn) {
    a[u] = sgn * (int)e[u].size();
    for (auto v : e[u]) {
        if (v == p) continue;
        dfs(v, u, sgn * -1);
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
        for (int i = 1; i < n; ++i) {
            int u, v;
            std::cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(1, 0, -1);
        for (int i = 1; i <= n; ++i) std::cout << a[i] << ' ';
        std::cout << '\n';
    }

    return 0;
}
// 13 : 45
/*

a b c d 
a = c + d
a + b = d

c + d + b = d
c + b  = 0

a b c d e

a = c + d + e
a + b = d + e
a + b + c = e

c + d + e + b = d + e
c + b = 0

e - c = d + e
d + c = 0

a b c
a = c
*/