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
int n, k;
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
        std::cin >> n >> k;
        if (n == 1) {
            std::cout << k << '\n';
        } else {
            ll x = 0;
            for (int i = 1; i <= 31; ++i) {
                if ((1ll << i) - 1 > k) {
                    x = (1ll << (i - 1)) - 1;
                    break;
                }
            }
            std::cout << x << ' ' << k - x << ' ';
            for (int i = 3; i <= n; ++i) {
                std::cout << 0 << ' ';
            }
            std::cout << '\n';
        }
    }

    return 0;
}
