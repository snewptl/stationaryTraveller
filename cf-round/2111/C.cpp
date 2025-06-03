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
const int maxn = 5e5 + 5;
int n, a[maxn];
void solve() {
    ll ans = 1e18;
    int last = 1;
    for (int i = 2; i <= n; ++i) {
        if (a[i] != a[last]) {
            ans = std::min(ans, 1ll * (n - (i - 1 - last + 1)) * a[last]);
            last = i;
        }
    }
    ans = std::min(ans, 1ll * (last - 1) * a[last]);
    std::cout << ans << '\n';
}
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
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        solve();
    }

    return 0;
}
