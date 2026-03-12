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
const int maxn = 1e3 + 5;
const ll mod = 998244353;
int n, m;
int r, c;
int a[maxn][maxn];
std::vector<std::pair<int, pii>> vec;
std::vector<ll> prob;
std::vector<pll> linear, square;
ll qp(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y & 1) {
            res *= x;
            res %= mod;
        }
        x *= x;
        x %= mod;
        y /= 2;
    }
    return res;
}
ll inv(ll x) {
    return qp(x, mod - 2);
}
void add(pll & x, pll & y) {
    x.first += y.first;
    x.first %= mod;
    x.second += y.second;
    x.second %= mod;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int cur;
            std::cin >> cur;
            a[i][j] = cur;
            vec.push_back({-cur, {i, j}});
        }
    }
    std::cin >> r >> c;
    int len = n * m;
    std::sort(all(vec));
    prob.resize(len, 0);
    linear.resize(len, {0, 0});
    square.resize(len, {0, 0});
    for (int i = len - 1; i >= 0; --i) {
        auto [x, y] = vec[i].second;
        linear[i] = {x, y};
        square[i] = {1ll * x * x % mod, 1ll * y * y % mod};
        if (i != len - 1) {
            add(linear[i], linear[i + 1]);
            add(square[i], square[i + 1]);
        }
    }
    ll ans = 0;
    for (int i = 0;  i < len; ++i) {
        if (i) {
            prob[i] += prob[i - 1];
            prob[i] %= mod;
        }
        auto [val, pos] = vec[i];
        auto [x, y] = pos;
        if (x == r && y == c) prob[i] = 1;
        auto it = std::lower_bound(vec.begin(), vec.end(), std::make_pair(val + 1, std::make_pair(0, 0))) - vec.begin();
        int remain = len - it;
        if (remain) {
            ll delta = inv(remain);
            prob[it] += delta * prob[i];
            prob[it] %= mod;
            ans += prob[i] * ( (1ll * x * x + 1ll * y * y) % mod )% mod;
            ans %= mod;
            ans -= prob[i] * delta % mod * 2 * x % mod * linear[it].first % mod;
            ans = (ans + mod) % mod;
            ans -= prob[i] * delta % mod * 2 * y % mod * linear[it].second % mod;
            ans = (ans + mod) % mod;
            ans += prob[i] * delta % mod * (square[it].first + square[it].second) % mod;
            ans %= mod;
        }
        if (x == r && y == c) prob[i] = 0;
    }
    std::cout << ans << '\n';


    return 0;
}
