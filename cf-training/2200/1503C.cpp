#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <assert.h>
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
pll a[maxn];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i].first >> a[i].second;
        ans += a[i].second;
    }
    std::sort(a + 1, a + n + 1);
    std::set<ll> s;
    s.insert(-(a[1].first + a[1].second));
    for (int i = 2; i <= n; ++i) {
        ans += std::max(0ll, a[i].first + *s.begin());
        s.insert(-(a[i].first + a[i].second));
    }
    std::cout << ans << '\n';

    return 0;
}
