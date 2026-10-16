#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <assert.h>
#include <memory.h>
#include <cmath>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
const ll mod = 998244353;
int n;
int x1, x2, k;
int dis(int x, int y) {
    x -= 1;
    y -= 1;
    return std::min((x + n - y) % n, (y + n - x) % n);
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> x1 >> x2 >> k;
        if (n == 2 || n == 3) {
            std::cout << 1 << '\n';
        } else {
            int ans = 0;
            if (n % 2 == 0 && dis(x1, x2) == n / 2) {
                x1 += 1;
                if (x1 > n) x1 = 1;
                ans += 1; 
            }
            ans += k + dis(x1, x2);
            std::cout << ans << '\n';
        }
    }

    return 0;
}
