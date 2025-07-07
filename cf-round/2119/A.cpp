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
int x, y, a, b;
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
        std::cin >> a >> b >> x >> y;
        if (a > b) {
            if (a - b > 1) std::cout << "-1\n";
            else {
                if (a % 2 == 1) std::cout << y << '\n';
                else std::cout << "-1\n";
            }
        } else {
            int ans = 0;
            for (int i = a; i < b; ++i) {
                if (i % 2 == 0) ans += std::min(x, y);
                else ans += x;
            }
            std::cout << ans << '\n';
        }
    }

    return 0;
}
