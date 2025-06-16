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
int n, a[maxn], b[maxn];
bool check(int x) {
    int mn = n * 2 + 1, mn_pos = 0;
    for (int i = 1; i <= x; ++i) {
        if (mn > a[i]) mn = a[i], mn_pos = i;
    }
    int mx = 0, mx_pos = 0;
    for (int i = x + 1; i <= n; ++i) {
        if (mx < a[i]) mx = a[i], mx_pos = i;
    }
    if (mn_pos && mx_pos && mn < mx) std::swap(a[mn_pos], a[mx_pos]);
    int res = 0, wall = 2 * n + 1, flag = 1;
    for (int i = 1; i <= n - x + 1; ++i) {
        wall = std::min(wall, b[i]);
    }
    for (int i = 1; i <= x; ++i) {
        if (a[i] < wall) flag = 0;
    }
    if (mn_pos && mx_pos && mn < mx) std::swap(a[mn_pos], a[mx_pos]);
    return flag;
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
        for (int j = 1; j <= n; ++j) std::cin >> b[j];
        int l = 1, r = n, ans = 0;
        while (l <= r) {
            int mid = l + r >> 1;
            if (check(mid)) l = mid + 1, ans = mid;
            else r = mid - 1;
        }
        std::cout << ans << '\n';
    }

    return 0;
}
