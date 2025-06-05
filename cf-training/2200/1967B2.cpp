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
        ll ans = 0;
        for (int d = 2; d <= std::min(m, n); ++d) {
            int up = m / d;
            for (int j = 1; j <= up; ++j) {
                int x = j, y = d - j;
                if (y <= 0) continue;
                if (std::__gcd(x, y) != 1) continue;
                if (y * d > n) continue;
                ans += std::min(m / (1ll * x * d), n / (1ll * y * d));
            }
        }
        std::cout << ans << '\n';
    }

    return 0;
}
