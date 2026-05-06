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
ll a[maxn];
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
        std::cin >> n;
        ll mx = 0;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            mx = std::max(mx, a[i]);
        }
        for (int i = 1; i <= n; ++i) {
            if (a[i] == mx) {
                std::swap(a[1], a[i]);
                break;
            }
        }
        std::sort(a + 2, a + n + 1);
        std::unique(a + 2, a + n + 1);
        ll ans = n * mx;
        std::set<int> s;
        for (int i = 0; i <= n; ++i) {
            s.insert(i);
        }
        for (int i = 1; i <= n; ++i) {
            s.erase(a[i]);
            ans += *s.begin();
        }
        std::cout << ans << '\n';
    }

    return 0;
}
