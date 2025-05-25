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
int n, m, q;
int b[maxn];
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
        std::cin >> n >> m >> q;
        for (int i = 1; i <= m; ++i) {
            std::cin >> b[i];
        }
        std::sort(b + 1, b + m + 1);
        for (int i = 1; i <= q; ++i) {
            int a; std::cin >> a;
            auto it = std::upper_bound(b + 1, b + m + 1, a);
            int ans = 0;
            if (it == b + m + 1) {
                ans = n - b[m];
            } else if (it == b + 1) {
                ans = b[1] - 1;
            } else {
                ans = (b[it - b] - b[it - b - 1]) / 2;
            }
            std::cout << ans << '\n';
        }
    }

    return 0;
}
