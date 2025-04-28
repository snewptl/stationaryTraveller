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
int n, y;
std::vector<pii> e[maxn];
int dfs(int u, int fa, int limit){
    int sz = 1;
    for(auto p: e[u]) {
        int v = p.first, w = p.second;
        if (v == fa) continue;
        if(w >= limit) {
            sz += dfs(v, u, limit);
        }
    }
    return sz;
}
bool check(int x) {
    if (dfs(0, -1, x) <= y) return true;
    return false;
}
int main() {
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    // std::cin >> T;
    while (T--) {
        std::cin >> n >> y;
        for (int i = 1; i < n; ++i) {
            int u, v, w;
            std::cin >> u >> v >> w;
            e[u].push_back({v, w});
            e[v].push_back({u, w});
        }
        int l = 0, r = 1e8, ans = 1e8;
        while(l <= r) {
            int mid = (l + r) / 2;
            if (check(mid)){
                r = mid - 1;
                ans = std::min(ans, mid);
            } else {
                l = mid + 1;
            }
        }
        std::cout << ans << '\n';
    }

    return 0;
}
