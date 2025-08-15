#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <assert.h>
#include <memory.h>
#include <array>
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
const ll inf = 1e18;
const int len = 500;
std::vector<std::array<std::array<ll, 2>, 2>> seg;
std::vector<pii> loc;
int n;
ll a[maxn];
ll dp[2][maxn];
int q;
int get_id(int p) {
    return (p - 1) / len;
}
std::array<std::array<ll, 2>, 2> get_arr(int l, int r) {
    std::array<std::array<ll, 2>, 2> arr;
    if (l != 1) dp[0][l] = 0;
    else dp[0][l] = inf;
    dp[1][l] = inf;
    for (int j = l + 1; j <= r; ++j) {
        dp[0][j] = dp[1][j - 1];
        if (j < n) dp[1][j] = std::min(dp[0][j - 1], dp[1][j - 1]) + a[j] * 2;
        else dp[1][j] = inf;
    }

    arr[0][0] = dp[0][r];
    arr[0][1] = dp[1][r];

    dp[0][l] = inf;
    if (l < n) dp[1][l] = a[l] * 2;
    else dp[1][l] = inf;
    for (int j = l + 1; j <= r; ++j) {
        dp[0][j] = dp[1][j - 1];
        if (j < n) dp[1][j] = std::min(dp[0][j - 1], dp[1][j - 1]) + a[j] * 2;
        else dp[1][j] = inf;
    }
    
    arr[1][0] = dp[0][r];
    arr[1][1] = dp[1][r];
    return arr;
}
ll solve() {
    ll res[2] = {0, inf};
    for (auto arr : seg) {
        ll cur[2] = {0, 0};
        cur[0] = std::min(res[0] + arr[1][0], res[1] + std::min(arr[0][0], arr[1][0]));
        cur[1] = std::min(res[1] + std::min(arr[0][1], arr[1][1]), res[0] + arr[1][1]);
        res[0] = cur[0];
        res[1] = cur[1];
    }
    return res[0];
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for (int i = 1; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; i += len) {
        int l = i, r = std::min(i + len - 1, n);
        loc.push_back({l, r});
        seg.push_back(get_arr(l, r));
    }
    std::cin >> q;
    for (int i = 1; i <= q; ++i) {
        int k, x;
        std::cin >> k >> x;
        int id = get_id(k);
        a[k] = x;
        auto [l, r] = loc[id];
        seg[id] = get_arr(l, r);
        std::cout << solve() << '\n';
    }
    

    return 0;
}
// 15 : 46 - 17 : 24