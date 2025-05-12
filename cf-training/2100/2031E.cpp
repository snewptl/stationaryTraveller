// WA on 2
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
int n;
std::vector<int> e[maxn];
int dep[maxn];
int maxdep;
void dfs(int u, int p) {
    for (auto v : e[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    std::set<pii> s;
    for (auto v : e[u]) {
        if (v == p) continue;
        s.insert({dep[v], v});
    }

    int size = (p ? e[u].size() - 1 : e[u].size());
    int base_delta = 0;
    while (size) {
        int cur = 1, delta = base_delta;
        while (cur < size) cur *= 2, delta += 1;
        if (cur == 1 && base_delta == 0) delta = 1, size = 0;
        else if (size == cur) size = 0;
        else cur /= 2, size -= cur;
        while (cur) {
            --cur;
            dep[u] = std::max(dep[u], s.begin()->first + delta); 
            s.erase(s.begin());
        }
        base_delta++;
    }
    if (u == 1) maxdep = dep[1];
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
        maxdep = 0;
        for (int i = 1; i <= n; ++i) {
            e[i].clear();
            dep[i] = 0;
        }
        for (int i = 1; i < n; ++i) {
            int u, v = i + 1;
            std::cin >> u;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(1, 0);
        std::cout << maxdep << '\n';
    }

    return 0;
}
