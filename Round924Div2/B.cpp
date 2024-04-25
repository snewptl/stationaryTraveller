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
const int maxn = 2e5 + 5;
int n, a[maxn];
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        std::sort(a + 1, a + n + 1);
        int m = std::unique(a + 1, a + n + 1) - (a + 1);
        int ans = 0;
        for(int i = 1; i <= m; ++i) {
            auto it = std::lower_bound(a + 1, a + m + 1, a[i] + n);
            ans = std::max(ans, int(it - (a + i)));
        } 
        std::cout << ans << '\n';
    }

    return 0;
}
   