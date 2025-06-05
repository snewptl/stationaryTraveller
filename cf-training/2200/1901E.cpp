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
const int maxn = 5e5 + 5;
const ll mod = 998244353;
ll link[maxn];
int n;
ll a[maxn];
ll ans;
std::vector<std::vector<int>> e;
void dfs(int u, int p) {
    std::vector<ll> vec;
    ans = std::max(a[u], ans);
    for (auto v : e[u]) {
        if (v == p) continue;
        dfs(v, u);
        vec.push_back(link[v]);
    }
    std::sort(all(vec), std::greater<ll>());
    if (vec.size() == 0) {
        link[u] = a[u];
    } else if (vec.size() == 1) {
        link[u] = std::max(a[u], vec[0]);
        ans = std::max(ans, a[u] + vec[0]);
    } else if (vec.size() >= 2) {
        ll sum = 0, count = 0;
        for (auto it : vec) {
            if (it < 0 && count >= 2) break;
            sum += it;
            ++count;
        }
        link[u] = std::max(sum + a[u], std::max(vec[0], a[u]));
        ll temp = -1e18;
        if (vec.size() > 2 && count == 2) sum += vec[count], ++count;
        if (count > 2) temp = sum + a[u];
        std::vector<ll> comp;
        comp.push_back(a[u]);
        comp.push_back(vec[0]);
        comp.push_back(vec[1]);
        std::sort(all(comp), std::greater<ll>());
        temp = std::max(temp, comp[0] + comp[1]);
        ans = std::max(ans, temp);
    }
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
        for (int i = 1; i <= n; ++i) {
            link[i] = -1e16;
        }
        ans = 0;
        e.clear();
        e.resize(n + 1);
        for(int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        for (int i = 1; i < n; ++i) {
            int u, v;
            std::cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(1, 0);
        std::cout << ans << '\n';
    }

    return 0;
}
