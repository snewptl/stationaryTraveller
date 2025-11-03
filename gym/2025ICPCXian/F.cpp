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
const int maxn = 5e5 + 5;
const ll mod = 998244353;
int n, t[maxn];
int a[maxn];
std::vector<std::vector<pii>> vec;
int vis[maxn];
int dir[maxn], stopped[maxn], end[maxn];
std::vector<std::vector<int>> e;
int in[maxn];
bool check(int id, int to) {
    if (a[id] == a[to]) {
        return to < id;
    }
    if (dir[to] != dir[id]) {
        int third = t[to];
        if (dir[third] != dir[to]) {
            ll res = 1ll * (a[third] - a[id]) * (a[third] - a[to]);
            if (res < 0) return true;
            else if (res == 0) {
                return to < id;
            }
        } else {
            return 
        }
    } else {
        return true;
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
    for (int i = 1; i <= n; ++i) {
        std::cin >> t[i];
    }
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    e.resize(n + 1);
    vec.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        int cur = i;
        while (!vis[cur]) {
            vis[cur] = i;
            vec[i].push_back({a[cur], cur});
            cur = t[cur];
        }
    }
    for (int i = 1; i <= n; ++i) {
        // std::sort(all(vec[i]));
        for (auto [pos, id] : vec[i]) {
            int to = t[id];
            if (a[to] <= a[id]) {
                dir[id] = 0;
            } else {
                dir[id] = 1;
            }
        }
        for (auto [pos, id] : vec[i]) {
            int to = t[id];
            if (check(id, to)) {
                in[id] += 1;
                e[to].push_back(id);
            } else {
                in[to] += 1;
                e[id].push_back(to);
            }
        }
        std::queue<int> q;
        for (auto [pos, id] : vec[i]) {
            if (in[id] == 0) q.push(id);
        }
        int cur = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            int to = t[u];
            if (dir[to] != dir[u]) {
                if (!stopped[to]) {
                    assert(cur <= std::abs(a[u] - a[to]));
                    cur = std::abs(a[u] - a[to]);
                } else {
                    assert(cur <= std::abs(a[u] - a[to]) * 2 - end[to]);
                    cur = std::abs(a[u] - a[to]) * 2 - end[to]; 
                }
            } else {
                assert(stopped[to] || a[to] == a[u]);
                assert(cur <= std::abs(a[u] - a[to]) * 2 + end[to]);
                cur = std::abs(a[u] - a[to]) * 2 + end[to];
            }
            end[u] = cur;
            stopped[u] = 1;
            for (auto v : e[u]) {
                in[v] -= 1;
                if (!in[v]) {
                    q.push(v);
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        std::cout << end[i] << ' ';
    }
    std::cout << '\n';
    

    return 0;
}
