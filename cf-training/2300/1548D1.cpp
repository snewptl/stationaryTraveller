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
ll n;
pii a[maxn];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    // std::cin >> T;
    while (T--) {
        std::cin >> n;
        ll ans = n * (n - 1) * (n - 2) / 6;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i].first >> a[i].second;
        }
        std::sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; ++i) {
            ll odd_odd = 0, odd_even = 0, even_odd = 0;
            for (int j = i + 1; j <= n; ++j) {
                ll x = std::abs(a[i].first - a[j].first);
                ll y = std::abs(a[i].second - a[j].second);
                x /= 2;
                y /= 2;
                if (x % 2) {
                    if (y % 2) odd_odd += 1, ans -= (odd_even + even_odd);
                    else odd_even += 1, ans -= (odd_odd + even_odd);
                } else if (y % 2) {
                    even_odd += 1, ans -= (odd_odd + odd_even);
                }
                
            }
        }
        std::cout << ans << '\n';
    }

    return 0;
}
// 18 : 40 - 19 : 08