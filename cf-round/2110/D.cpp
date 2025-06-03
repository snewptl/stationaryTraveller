#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
int n, m;
std::vector<std::vector<pii>> e;
int b[maxn];
int dis[maxn];
int in[maxn];
bool check(int x) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    q.push(1);
    for (int i = 1; i <= n; ++i) dis[i] = 0, in[i] = 0;
    dis[1] = std::min(b[1], x);
    in[1] = 1;
    while(!q.empty()) {
        auto u = q.top(); q.pop();
        if (u == n) return true;
        for (auto [v, w] : e[u]) {
            if (w > dis[u]) continue;
            if (!in[v]) q.push(v);
            in[v] = 1;
            dis[v] = std::max(dis[v], dis[u] + b[v]);
            dis[v] = std::min(x, dis[v]);
        }
    }
    return false;
}
void solve() {
    int l = 1, r = 1e9, res = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) r = mid - 1, res = mid;
        else l = mid + 1;
    }
    std::cout << res << '\n';
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
        std::cin >> n >> m;
        for (int i = 1; i <= n; ++i) std::cin >> b[i];
        e.clear();
        e.resize(n + 1);
        for (int i = 1; i <= m; ++i) {
            int u, v, w;
            std::cin >> u >> v >> w;
            e[u].push_back({v, w});
        }
        solve();
    }

    return 0;
}
