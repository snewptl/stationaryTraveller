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
int n, a[maxn], count[maxn], vis[maxn];
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
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        std::vector<pll> vec;
        vec.push_back({a[n], 1});
        ll ans = 0;
        for (int i = n - 1; i >= 1; --i) {
            std::vector<pll> temp;
            for (auto [wall, times] : vec) {
                if (a[i] <= wall) {
                    temp.push_back({a[i], times});
                    continue;
                }
                else {
                    ll group = a[i] / wall;
                    ll cur = a[i] / group;
                    ll start = cur, end = cur + 1;
                    if (a[i] % group == 0) end -= 1;
                    if (end > wall) {
                        ++group;
                        cur = a[i] / group;
                        start = cur, end = cur + 1;
                        if (a[i] % group == 0) end -= 1;
                    }
                    assert(end <= wall);
                    ans += times * (group - 1) % mod * i % mod;
                    ans %= mod;
                    temp.push_back({start, times});
                }
            }
            temp.push_back({a[i], 1});
            vec.clear();
            for (auto [wall, times] : temp) {
                count[wall] = 0;
                vis[wall] = 0;
            }
            for (auto [wall, times] : temp) {
                count[wall] += times;
            }
            for (auto [wall, _] : temp) {
                if (vis[wall]) continue;
                vec.push_back({wall, count[wall]});
                vis[wall] = 1;
            }
        }
        std::cout << ans << '\n';
    }

    return 0;
}
// 20 : 42 - 21 : 28