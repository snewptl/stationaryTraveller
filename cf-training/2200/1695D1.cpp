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
int vis[maxn];
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
        for (int i = 1; i <= n; ++i) vis[i] = 0;
        for (int i = 1; i < n; ++i) {
            int u, v;
            std::cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        int ans = 0;
        for (int t = 1; t <= n; ++t) {
            for (int i = 1; i <= n; ++i) {
                if (e[i].size() != 1) continue;
                std::vector<int> vec;
                int count = 0, tot = 0;
                int rt = e[i][0];
                for (auto v : e[rt]) {
                    if (e[v].size() == 1) {
                        tot += 1;
                        if (!vis[v]) count += 1;
                        vis[v] = 1;
                    } else {
                        vec.push_back(v);
                    }
                }
                if (count >= 2) {
                    ans += count - 1;
                    vis[rt] = 1;
                } else if (count == 1) {
                    if (tot > 1) {
                        ans += 1;
                        vis[rt] = 1;
                    }
                }
                e[rt].clear();
                for (auto it : vec) e[rt].push_back(it);
            }
        }

        std::cout << (n == 1 ? 0 : std::max(ans, 1)) << '\n';
    }

    return 0;
}

// 2 : 20