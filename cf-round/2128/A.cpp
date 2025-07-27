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
int n, c, a[maxn];
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
        std::cin >> n >> c;
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        std::sort(a + 1, a + n + 1);
        ll mul = 1, ans = 0;
        for (int i = n; i >= 1; --i) {
            if (mul * a[i] > c) ans += 1;
            else {
                mul *= 2;
            }
        }
        std::cout << ans << '\n';
    }

    return 0;
}
