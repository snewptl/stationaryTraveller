#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxN = 2e5 + 5;
std::vector<int> edge[maxN];
int n, k, size[maxN];
int tot;
int tryCut(int u, int p, int x) {
    int res = 0;
    size[u] = 1;
    for (auto v : edge[u]) {
        if (v == p) continue;
        res += tryCut(v, u, x);
        if (size[v] >= x &&  tot - size[v] >= x){
            res++;
            tot -= size[v];
        } else {
            size[u] += size[v];
        }
    }
    return res;
}
bool check(int x) {
    tot = n;
    return tryCut(1, 0, x) >= k;
}
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> k;
        for (int i = 1; i < n; ++i) {
            int u, v;
            std::cin >> u >> v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        int l = 1, r = n, ans = 0;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if (check(mid)){
                l = mid + 1, ans = std::max(ans, mid);
            } else {
                r = mid - 1;
            }
        }
        std::cout << ans << '\n';
        for (int i = 1; i <= n; ++i) edge[i].clear();
    }

    return 0;
}
