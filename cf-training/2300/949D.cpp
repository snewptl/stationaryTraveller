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
ll n, d;
ll b;
ll a[maxn];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> d >> b;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    int ans = (n + 1) / 2;
    ll end = (n + 1) / 2, now = 1, last = 0;
    pii le_border = {1, d + 1}, ri_border = {n - d, n};
    while (now <= end) {
        ll cur_le = b;
        le_border.second = std::min(now + d * now, n);
        while (now <= end && cur_le) {
            ll min = std::min(a[le_border.first], cur_le);
            cur_le -= min;
            a[le_border.first] -= min;
            if (cur_le) {
                if (!a[le_border.first]) ++le_border.first;
                if (le_border.first > le_border.second) {
                    ++now;
                    le_border.second = std::min(now + d * now, n);
                }
            }
        }

        ri_border.first = std::max(1ll, n - now + 1 - d * now);
        ll cur_ri = b;
        while (now <= n / 2 && cur_ri) {
            ll min = std::min(a[ri_border.second], cur_ri);
            cur_ri -= min;
            a[ri_border.second] -= min;
            if (cur_ri) {
                if (!a[ri_border.second]) --ri_border.second;
                if (ri_border.first > ri_border.second) {
                    ++now;
                    ri_border.first = std::max(1ll, n - now + 1 - d * now);
                }

            }
        }

        if (cur_le) {
            break;
        } else {
            if (cur_ri) {
                if (n % 2) ans -= 1;
                break;
            } else {
                ans -= 1;
                ++now;
            }
        }
    }
    std::cout << ans << '\n';

    return 0;
}
