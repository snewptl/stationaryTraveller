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
int n, q;
ll a[maxn];
ll delta[maxn];
ll sum;
ll cal(ll x) {
    ll res = x / 2;
    if (res * 2 < x) res += 1;
    return res;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    for (int i = 1; i < n; ++i) {
        delta[i] = a[i + 1] - a[i];
        sum += std::max(delta[i], 0ll);
    }
    std::cout << cal(sum + a[1]) << '\n';
    std::cin >> q;
    while (q--) {
        int l, r, x;
        std::cin >> l >> r >> x;
        a[l] += x;
        if (l > 1) {
            sum -= std::max(delta[l - 1], 0ll);
            delta[l - 1] += x;
            sum += std::max(delta[l - 1], 0ll);
        }
        if (r < n) {
            sum -= std::max(delta[r], 0ll);
            delta[r] -= x;
            sum += std::max(delta[r], 0ll);
        }
        std::cout << cal(sum + a[1]) << '\n';
    }

    return 0;
}
// 20 : 38 - 21 : 06