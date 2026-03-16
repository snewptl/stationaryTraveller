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
int n, d;
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
    int ans = 0;
    int end = (n + 1) / 2, now = 1, last = 0;
    pii le_border = {1, d + 1}, ri_border = {n - d, n};
    while (now <= end) {
        ll cur_le = b;
        while (le_border.second <= n && cur_le) {
            ll min = std::min(a[le_border.first], cur_le);
            cur_le -= min;
            a[le_border.first] -= min;
            if (!a[le_border.first]) ++le_border.first;
            if (cur_le && le_border.first > le_border.second) {
                ++le_border.second;
                ++now;
            }
        }
        ll cur_ri = b;
        while (ri_border.first <= ri_border.second && cur_ri) {
            ll min = std::min(a[ri_border.second], cur_ri);
            cur_ri -= min;
            a[ri_border.second] -= min;
            if (!a[ri_border.second]) --ri_border.second;
        }
        if (cur_le || cur_ri) {
            if (le_border.first == 1) {
                a[1] += b - 
            }
            --le_border.first;
            a[le_border.first] = b - cur_le;

        } else {

        }
        
        ++le_border.second;
        le_border.second = std::min(le_border.second, n);
        --ri_border.first;
        ri_border.first = std::max(ri_border.first, 1);
    }
    

    return 0;
}
