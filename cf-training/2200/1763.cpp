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
int p;
pll dp[maxn];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> p;
    std::queue<int> q;
    for (int i = 1; i <= p; ++i) dp[i] = {1e18, 0};
    for (ll i = 0; i <= p; ++i) {
        for (ll j = 2; j * (j - 1) / 2 + i <= p; ++j) {
            auto [dep, val] = dp[i];
            ll new_idx = j * (j - 1) / 2 + i;
            ll new_val = val + j * dep;
            ll new_dep = j + dep;
            if (dp[new_idx].first > new_dep) {
                dp[new_idx] = {new_dep, new_val};
            } else if (dp[new_idx].first == new_dep) {
                dp[new_idx].second = std::max(dp[new_idx].second, new_val);
            }
        } 
    }
    std::cout << dp[p].first << " " << dp[p].second << '\n';
    return 0;
}

// 00 : 30