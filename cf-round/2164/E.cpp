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
const int maxn = 1e6 + 5;
const ll mod = 998244353;
int n, m;
std::pair<ll, pii> e[maxn];
int fa[maxn];
int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int count[maxn], deg[maxn];
ll ans;
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
        std::cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            fa[i] = i;
            count[i] = 0;
            deg[i] = 0;
        }
        ans = 0;
        for (int i = 1; i <= m; ++i) {
            int u, v;
            ll w;
            std::cin >> u >> v >> w;
            ans += w;
            deg[u] += 1;
            deg[v] += 1;
            e[i] = {w, {u, v}};
        }
        for (int i = 1;i <= n; ++i) {
            count[i] = deg[i] % 2;
        }
        std::vector<int> vec;
        for (int i = 1; i <= m; ++i) {
            while (!vec.empty()) {
                auto [val, _] = e[vec.back()];
                if (val >= e[i].first) {
                    vec.pop_back();
                } else {
                    break;
                }
            }
            vec.push_back(i);
        }
        int last = 0;
        int fin = 0, flag = (count[1]), del = 0;
        for (auto cur : vec) {
            int val = e[cur].first, rt;
            for (int i = last + 1; i <= cur; ++i) {
                auto [_, p] = e[i];
                auto [u, v] = p;
                if (find(u) != find(v)) {
                    count[find(u)] += count[find(v)];
                    count[find(v)] = 0;
                    fa[find(v)] = find(u);
                    rt = find(u);
                }
            }
            if (count[rt] >= 2) {
                ans += 1ll * (count[rt]) / 2 * val;
                if (flag && (find(1) == rt)) flag = 0, ans -= val;
                fin = std::max(val, fin);
                count[rt] %= 2;
            }
            last = cur;
        }
        ans +=  fin;
        std::cout << ans << '\n';
    }

    return 0;
}
