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
const pii end = {-1, -1};
int n, m, k;
ll a[maxn], b[maxn];
int sz[2];
struct people {
    ll t;
    int type, id; 
    bool operator<(people &x) {
        return t < x.t;
    }
};
people seg[2][maxn];
std::map<pii, ll> dp[2];
void add (int type, pii p, ll val) {
    if (!dp[type].count(p)) {
        dp[type][p] = val;
    } else {
        dp[type][p] = std::min(dp[type][p], val);
    }
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        people cur = {a[i], 0, i};
        seg[0][i] = cur;
    }
    for (int i = 1; i <= m; ++i) {
        std::cin >> b[i];
        people cur = {b[i], 0, i};
        seg[1][i] = cur;
    }
    sz[0] = n;
    sz[1] = m;
    std::sort(seg[0] + 1, seg[0] + n + 1);
    std::sort(seg[1] + 1, seg[1] + m + 1);

    dp[0][{0, 0}] = 0;
    dp[1][{0, 0}] = 0;
    std::set<pii> s;
    s.insert({0, 0});
    while (!s.empty()) {
        auto [i, j] = *s.begin();
        s.erase(s.begin());
        if (dp[0].count({i, j})) {
            if (i < n) {
                if (dp[0][{i, j}] >= seg[0][i + 1].t) {
                    add(1, {i + 1, j}, dp[0][{i, j}] + k);
                } else if (j >= m || seg[0][i + 1].t < std::max(seg[1][j + 1].t, k + dp[0][{i, j}]) + k) {
                    add(1, {i + 1, j}, seg[0][i + 1].t + k);
                }
            }
            if (j < m) {
                if (i < n && dp[0][{i, j}] >= seg[0][i + 1].t);
                else if (i >= n || seg[0][i + 1].t + k > seg[1][j + 1].t) {
                    add(0, {i, j + 1}, std::max(dp[0][{i, j}] + k, seg[1][j + 1].t) + k);
                }
            }
        }
        if (dp[1].count({i, j})) {
            if (j < m) {
                if (dp[1][{i, j}] >= seg[1][j + 1].t) {
                    add(0, {i, j + 1}, dp[1][{i, j}] + k);
                } else if (i >= n || seg[1][j + 1].t < std::max(seg[0][i + 1].t, k + dp[1][{i, j}]) + k) {
                    add(0, {i, j + 1}, seg[1][j + 1].t + k);
                }
            }
            if (i < n) {
                if (j < m && dp[1][{i, j}] >= seg[1][j + 1].t);
                else if (j >= m || seg[1][j + 1].t + k > seg[0][i + 1].t) {
                    add(1, {i + 1, j}, std::max(dp[1][{i, j}] + k, seg[0][i + 1].t) + k);
                }
            }
        }
    }
    ll ans = 1e18;
    if (dp[0].count({n, m})) ans = dp[0][{n, m}];
    if (dp[1].count({n, m})) ans = std::min(ans, dp[1][{n, m}]);
    std::cout << ans << '\n';

    return 0;
}
