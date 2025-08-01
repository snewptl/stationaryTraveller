#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <bitset>
#include <memory.h>
#include <assert.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
const ll mod = 998244353;
int n, N;
std::vector<std::vector<pii>> e;
int vis[maxn];
std::vector<int> used;
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
        N = n * 2;
        e.resize(N + 1);
        used.clear();
        for (int i = 1; i <= N; ++i) {
            vis[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            int u, v;
            std::cin >> u >> v;
            e[u].push_back({v, i});
            e[v].push_back({u, i});
        }
        std::vector<pii> seg;
        for (int i = 1; i <= N; ++i) {
            if (!vis[i]) {
                std::queue<int> q;
                q.push(i);
                vis[i] = 1;
                int mx = i;
                while (!q.empty()) {
                    auto u = q.front(); q.pop();
                    for (auto [v, idx] : e[u]) {
                        if (!vis[v]) {
                            vis[v] = 1;
                            q.push(v);
                            used.push_back(idx); 
                            mx = std::max(mx, v);
                        }
                    }
                }
                seg.push_back({i, mx});
            }
        }
        // std::sort(all(seg));
        // int ans = 0, last_l = 0, last_r = 0;
        // for (auto [l, r] : seg) {
        //     if (l > last_r) {
        //         ans += last_r - last_l;
        //         last_l = l;
        //         last_r = r;
        //     } else {
        //         last_r = std::max(last_r, r);
        //     }
        // }
        // ans += last_r - last_l;
        // std::cout << ans << '\n';
        std::cout << used.size() << '\n';
        for (auto it : used) std::cout << it << ' ';
        std::cout << '\n';
    }

    return 0;
}
