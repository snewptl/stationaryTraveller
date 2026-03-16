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
int n, m, k;
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
        std::cin >> n >> m >> k;
        int ans = 0;
        int l = k - 1, r = n - k;
        if (l > r) std::swap(l, r);
        if (m <= 3 * l - 1) {
            ans = (m + 1) / 3 * 2;
            if ((m + 1) % 3 == 2) ans += 1; 
        } else {
            m -= 3 * l - 1;
            ans = l * 2;
            ans += std::min(m / 2, r - l);
        }
        ans += 1;
        std::cout << ans << '\n';
    }

    return 0;
}
