#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#define all(x) x.begin(), x.end()
typedef int64_t ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 3e5 + 5;
const ll mod = 998244353;
std::vector<int> edge[maxn];
int n, size[maxn];
ll ans;
void dfs(int u, int p) {
    size[u] = 1;
    ll current = 1;
    ll del = 0;
    for (auto v : edge[u]) {
        if (v == p) continue;
        dfs(v, u);
        size[u] += size[v];
        current *= size[v] + 1, current %= mod;
        del -= 1ll * size[v] * size[v];
    }
    current *= n - size[u] + 1, current %= mod;

    del -= 1ll * (n - size[u]) * (n - size[u]);
    del += 1ll * (n - 1) * (n - 1);
    del /= 2;
    del += (n - 1) + 1;

    current -= del;
    current = (current % mod + mod) % mod;

    ans += current, ans %= mod;
}
int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            edge[i].clear();
        for (int i = 1; i < n; ++i) {
            int u, v;
            std::cin >> u >> v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        ans = 1 + n + 1ll * n * (n - 1) / 2, ans %= mod;
        dfs(1, 0);
        std::cout << ans << '\n';
    }

    return 0;
}
