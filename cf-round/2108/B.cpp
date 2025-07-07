#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <bitset>
#include <memory.h>
#include <assert.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
const ll mod = 998244353;
int n, x;
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
        std::cin >> n >> x;
        if (n == 1) {
            std::cout << (x == 0 ? -1 : x) << '\n';
        } else {
            int ans = x;
            int cnt = 0;
            for (int j = 0; j < 30; ++j) {
                if ((1 << j) & x) cnt += 1;
            }
            if (cnt < n) {
                ans += (n - cnt) / 2 * 2;
                if ((n - cnt) % 2) {
                    if (cnt > 1) ans += 2;
                    else if (cnt == 1) {
                        if (x & 1) ans += 4;
                        else ans += 2;
                    } else {
                        ans += 4;
                    }
                }
            }

            std::cout << ans << '\n';
        }
    }

    return 0;
}
