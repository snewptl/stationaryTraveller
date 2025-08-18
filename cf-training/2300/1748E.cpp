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
const ll mod = 1e9 + 7;
int n, m, a[maxn];
int le[maxn], ri[maxn];
std::vector<std::vector<ll>> dp;
void dfs(int pos, int mx) {
    int l = le[pos], r = ri[pos];
    if (l < pos) {
        dfs(l, mx - 1);
    }
    if (r > pos) {
        dfs(r, mx);
    }
    for (int i = 1; i <= mx; ++i) {
        ll res0 = 1, res1 = 1;
        if (l < pos) res0 = dp[l][i - 1];
        if (r > pos) res1 = dp[r][i];
        dp[pos][i] = res0 * res1 % mod;
        dp[pos][i] += dp[pos][i - 1];
        dp[pos][i] %= mod;
    }
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
        std::cin >> n >> m;
        dp.clear();
        dp.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            dp[i].resize(m + 1);
        }
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        std::vector<pii> vec;
        a[0] = m + 1;
        vec.push_back({a[0], 0});
        for (int i = 1; i <= n; ++i) {
            int last = i;
            while (!vec.empty()) {
                auto [val, pos] = vec.back();
                if (val >= a[i]) {
                    le[i] = last;
                    break;
                } else {
                    last = pos;
                    vec.pop_back();
                }
            }
            vec.push_back({a[i], i});
        }
        a[n + 1] = m + 1;
        vec.clear();
        vec.push_back({a[n + 1], n + 1});
        for (int i = n; i >= 1; --i) {
            int last = i;
            while (!vec.empty()) {
                auto [val, pos] = vec.back();
                if (val > a[i]) {
                    ri[i] = last;
                    break;
                } else {
                    last = pos;
                    vec.pop_back();
                }
            }
            vec.push_back({a[i], i});
        }
        int mx = 0, pos = 0;
        for (int i = 1; i <= n; ++i) {
            if (mx < a[i]) {
                mx = a[i];
                pos = i;
            }
        }
        dfs(pos, m);
        std::cout << dp[pos][m] << '\n';
    }

    return 0;
}
// 17 : 25 - 18 : 06
