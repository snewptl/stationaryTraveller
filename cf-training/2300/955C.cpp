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
pii a[maxn];
std::set<std::pair<pii, int>> s[2];
pii cur;
int dir[maxn];
std::vector<std::vector<pii>> e; 
void insert(int x, int y, int id) {
    if (1ll * x * y >= 0) s[0].insert({{x, y}, id});
    else s[1].insert({{x, y}, id}); 
}
ll len(pii cur) {
    auto [x, y] = cur;
    return 1ll * x * x + 1ll * y * y;
}
void dfs(int u) {
    for (auto [v, w] : e[u]) {
        dir[v] = dir[u] * w;
        dfs(v); 
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
    e.resize(2 * n);
    int node_count = n;
    for (int i = 1; i <= n; ++i) {
        int x, y;
        std::cin >> x >> y;
        insert(x, y, i);
    }
    while (s[1].size() > 1 || s[0].size() > 1) {
        for (int t = 0; t < 2; ++ t) {
            if (s[t].size() > 1) {
                ++node_count;
                auto [pos1, id1] = *s[t].begin();
                s[t].erase(s[t].begin());
                auto [pos2, id2] = *s[t].begin();
                s[t].erase(s[t].begin());
                
                a[node_count] = {pos1.first - pos2.first, pos1.second - pos2.second};
                if (len(a[node_count]) > 1e12) {
                    a[node_count] = {pos1.first + pos2.first, pos1.second + pos2.second};
                    e[node_count].push_back({id1, 1});
                    e[node_count].push_back({id2, 1});
                } else {
                    e[node_count].push_back({id1, 1});
                    e[node_count].push_back({id2, -1});
                }
                insert(a[node_count].first, a[node_count].second, node_count);
            }
        }
    }
    if (s[1].size() == 1 && s[0].size() == 1) {
        auto [pos1, id1] = *s[0].begin();
        auto [pos2, id2] = *s[1].begin();
        ++node_count;
        a[node_count] = {pos1.first - pos2.first, pos1.second - pos2.second};
        if (len(a[node_count]) > 2e12) {
            a[node_count] = {pos1.first + pos2.first, pos1.second + pos2.second};
            e[node_count].push_back({id1, 1});
            e[node_count].push_back({id2, 1});
        } else {
            e[node_count].push_back({id1, 1});
            e[node_count].push_back({id2, -1});
        }
    }
    for (int i = 1; i <= node_count; ++i) {
        dir[i] = 1;
    }
    dfs(node_count);
    for (int i = 1; i <= n; ++i) {
        std::cout << dir[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}
// 17 : 10 - 