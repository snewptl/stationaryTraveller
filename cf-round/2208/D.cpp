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
const int maxn = 8e3 + 5;
const ll mod = 998244353;
int n;
int size[maxn];
int to[maxn][maxn];
std::set<int> fa[maxn];
std::vector<pii> e;
bool solve() {
    for (int i = 1; i <= n; ++i) {
        if (!to[i][i]) return false;
        for (int j = 1; j <= n; ++j) {
            if (i == j) continue;
            if (to[i][j] && to[j][i]) return false;
        }
    }
    std::priority_queue<pii> q;
    for (int i = 1; i <= n; ++i) {
        q.push(std::make_pair(size[i], i));
    }
    while (!q.empty()) {
        auto [_, u] = q.top(); 
        q.pop();
        for (auto anc : fa[u]) {
            e.push_back({anc, u});
        }
        for (int v = 1; v <= n; ++v) {
            if (u == v) continue; 
            if (to[u][v]) {
                if (size[u] <= size[v]) return false;
                std::vector<int> temp;
                for (auto anc : fa[v]) {
                    if (to[anc][u]) {
                        temp.push_back(anc);
                    }
                }
                for (auto anc : temp) {
                    fa[v].erase(anc);
                }
                fa[v].insert(u);
            }
        }
    }
    if (e.size() != n - 1) return false;
    std::vector<int> used(n + 1, 0);
    for (auto [u, v] : e) {
        used[u] = used[v] = 1;
        if (size[u] == size[v]) return false;
        for (int i = 1; i <= n; ++i) {
            if (to[v][i] && !to[u][i]) return false;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) return false;
    }
    std::cout << "Yes\n";
    for (auto [u, v] : e) {
        std::cout << u << ' ' << v << '\n';
    }
    return true;
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
        std::cin >> n;
        e.clear();
        for (int i = 1; i <= n; ++i) {
            std::string str;
            std::cin >> str;
            size[i] = 0;
            fa[i].clear();
            for (int j = 0; j < n; ++j) {
                if (str[j] == '1') {
                    to[i][j + 1] = 1;
                    size[i] += 1;
                } else {
                    to[i][j + 1] = 0;
                }
            }
            
        }
        if (!solve()) std::cout << "No\n";
    }

    return 0;
}
