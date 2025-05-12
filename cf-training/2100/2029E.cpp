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
const int maxn = 4e5 + 5;
int n, a[maxn];
namespace Prime {
    std::vector<int> vec;
    int vis[maxn], low[maxn];
    int limit = 4e5;
    void init() {
        for (int i = 2; i <= limit; ++i) {
            if (!vis[i]) vec.push_back(i), low[i] = i;
            for (auto cur : vec) {
                if (cur * i > limit) break;
                vis[cur * i] = 1;
                low[cur * i] = cur;
                if (i % cur == 0) break;
            }
            
        }
    }
}
int solve(int cnt, int cur) {
    if (cnt >= 2) return -1;
    else {
        if (!cnt) cur = Prime::low[a[1]];
        for (int i = 1; i <= n; ++i) {
            if (Prime::low[a[i]] == cur) continue;
            if (1ll * Prime::low[a[i]] * cur > a[i]) {
                return -1;
            }
        }
        return cur;
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
    Prime::init();
    while (T--) {
        std::cin >> n;
        int cnt = 0, cur = 0;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            if (!Prime::vis[a[i]] && a[i] != cur) cnt++, cur = a[i];
        }
        std::sort(a + 1, a + n + 1);
        std::cout << solve(cnt, cur) << '\n';
    }

    return 0;
}
