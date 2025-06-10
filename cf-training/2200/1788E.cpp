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
ll ans;
int n;
ll a[maxn];
std::set<pll> s;
ll sum[maxn];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for (int i = 1; i <= n; ++i) std::cin >> a[i], sum[i] = sum[i - 1] + a[i];
    s.insert({0, 0});
    for (int i = 1; i <= n; ++i) {
        auto it = s.upper_bound({sum[i], 1e18});
        if (it != s.begin()){
            --it;
            auto [pre, val] = *it;
            ans = std::max(ans, val + i);
        }
        pll p = {sum[i], -1e18};
        ll temp = ans - i;
        while (!s.empty()) {
            auto it = s.lower_bound(p);
            if (it == s.end()) break;
            if (it->second <= temp) s.erase(it);
            else break;
        }
        if (!s.empty()) {
            p.second = 1e18;
            auto it = s.upper_bound(p);
            if (it == s.begin()) {
                s.insert({sum[i], temp});
            } else {
                --it;
                if (it->second < temp) s.insert({sum[i], temp});
            }
        } else {
            s.insert({sum[i], temp});
        }
    }
    std::cout << ans << '\n';

    return 0;
}
