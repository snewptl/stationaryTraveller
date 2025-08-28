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
int n;
ll a[maxn];
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
        std::cin >> n;
        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        ll min = -a[1];
        for (int i = 2; i <= n; ++i) {
            ll delta = a[i];
            if (i % 2 == 1) delta *= -1;
            min += delta;
            if (min < 0) {
                ans += abs(min);
                if (i % 2 == 0) {
                    min = 0;
                } else {
                    delta += abs(min);
                    min = 0;
                }
            }
            min = std::min(delta, min);
        }
        std::cout << ans << '\n';
    }

    return 0;
}
