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
int dir[maxn], ans[maxn];
int instack[maxn];
std::vector<std::vector<pii>> e;
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
    vec.resize(n + 1);
    e.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        int cur = i;
        while (!vis[cur]) {
            vis[cur] = i;
            vec[i].push_back({a[cur], cur});
            cur = t[cur];
        }
    }
    for (int i = 1; i <= n; ++i) ans[i] = -1;
    for (int i = 1; i <= n; ++i) {
        for (auto [pos, id] : vec[i]) {
            int to = t[id];
            if (a[to] <= a[id]) {
                dir[id] = 0;
            } else {
                dir[id] = 1;
            }
        }
        std::set<pii> s;
        for (auto [pos, id] : vec[i]) {
            int to = t[id];
            int type;
            if (a[to] == a[id]) type = 2;
            else if (dir[to] == dir[id]) type = 1;
            else type = 2;
            e[to].push_back({id, type});
            if (type == 2) {
                s.insert({std::abs(a[to] - a[id]), id});
            }
        }
        while (!s.empty()) {
            auto [val, u] = *s.begin();
            s.erase(s.begin());
            ans[u] = val;
            for (auto [id, type] : e[u]) {
                if (ans[id] != -1) continue;
                if (type == 1)  {
                    s.insert({std::abs(a[id] - a[u]) * 2 + val, id});
                } else {
                    s.erase({std::abs(a[u] - a[id]), id});
                    s.insert({std::abs(a[u] - a[id]) * 2 - val, id});
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        std::cout << ans[i] << ' ';
    }
    std::cout << '\n';
    

    return 0;
}
