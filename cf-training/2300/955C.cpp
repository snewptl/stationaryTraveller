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
std::set<std::pair<pll, int>> s[3];
pii cur;
int dir[maxn];
std::vector<std::vector<pii>> e; 
void insert(ll x, ll y, int id) {
    pll realNode = {x, y};
    if (y < 0) x = -x, y = -y;
    if (y * y <= 3 * x * x) {
        if (x > 0) s[0].insert({realNode, id});
        else s[2].insert({realNode, id});
    }  else {
        s[1].insert({realNode, id});
    }
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
    for (int i = 1; i <= 2 * n - 1; ++i) {
        dir[i] = 1;
    }
    int node_count = n;
    for (int i = 1; i <= n; ++i) {
        int x, y;
        std::cin >> x >> y;
        insert(x, y, i);
    }
    while (s[1].size() > 1 || s[0].size() > 1 || s[2].size() > 1) {
        for (int t = 0; t < 3; ++ t) {
            if (s[t].size() > 1) {
                auto [pos1, id1] = *s[t].begin();
                s[t].erase(s[t].begin());
                auto [pos2, id2] = *s[t].begin();
                s[t].erase(s[t].begin());
                
                ++node_count;
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
    std::vector<std::pair<pll, int>> vec;
    for (int t = 0; t < 3; ++t) {
        if (s[t].size()) {
            assert(len(s[t].begin()->first) <= 1e12);
            vec.push_back(*s[t].begin());
        }
    }
    if (vec.size() == 3) {
        std::vector<std::pair<pll, int>> temp;
        int flag = 0;
        ++node_count;
        for (int i = 0; i < 3; ++i) {
            for (int j = i + 1; j < 3; ++j) {
                if (flag) break;
                auto [pos1, id1] = vec[i];
                auto [pos2, id2] = vec[j];
                flag = 1;
                a[node_count] = {pos1.first - pos2.first, pos1.second - pos2.second};
                if (len(a[node_count]) <= 1e12) {
                    e[node_count].push_back({id1, 1});
                    e[node_count].push_back({id2, -1});
                } else {
                    a[node_count] = {pos1.first + pos2.first, pos1.second + pos2.second};
                    if (len(a[node_count]) <= 1e12) {
                        e[node_count].push_back({id1, 1});
                        e[node_count].push_back({id2, 1});
                    } else {
                        flag = 0;
                    }
                }
                if (flag) {
                    temp.push_back({a[node_count], node_count});
                    for (int k = 0; k < 3; ++k) {
                        if (k == i || k == j) continue;
                        temp.push_back(vec[k]);
                        break;
                    }
                    vec = temp;
                }
            }
        }
    } 
    if (vec.size() == 2) {
        assert(len(vec[0].first) <= 1e12);
        assert(len(vec[1].first) <= 1e12);
        ++node_count;
        auto [pos1, id1] = vec[0];
        auto [pos2, id2] = vec[1];
        a[node_count] = {pos1.first - pos2.first, pos1.second - pos2.second};
        if (len(a[node_count]) <= 2e12) {
            e[node_count].push_back({id1, 1});
            e[node_count].push_back({id2, -1});
        } else {
            a[node_count] = {pos1.first + pos2.first, pos1.second + pos2.second};
            e[node_count].push_back({id1, 1});
            e[node_count].push_back({id2, 1});
        }
    }

    dfs(node_count);
    for (int i = 1; i <= n; ++i) {
        std::cout << dir[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}
// 17 : 10 - 