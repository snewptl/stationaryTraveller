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
const ll inf = 1e18;
int n;
ll k;
ll a[maxn], sum[maxn], count[maxn];
ll ans;
ll cal(ll x, int flag) {
    ll delta = 0;
    if (flag == 0) {
        int idx = std::upper_bound(a + 1, a + n + 1, x) - a;
        ll top_num = count[n] - count[idx - 1] - x * (n - idx + 1);
        ll place_num = x * (idx - 1) - count[idx - 1];
        if (top_num > place_num)  return inf;
        delta -= sum[n] - sum[idx - 1] + (x + 1) * x / 2 * top_num;
        delta += top_num * k;
    } else {
        int idx = std::lower_bound(a + 1, a + n + 1, x) - a;
        --idx;
        ll place_num = x * idx - count[idx];
        ll top_num = count[n] - count[idx] - x * (n - idx);
        if (top_num < place_num) return inf;
        delta += place_num * k;
        int l = 0, r = n, max_i = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (count[n] - count[mid] - (a[mid] * (n - mid)) <= place_num) {
                max_i = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        delta -= sum[n] - sum[max_i] + (a[max_i] + 1) * a[max_i] / 2 * (n - max_i);
    }
    return sum[n] + delta;
}
void search(int l, int r, int flag) {
    while (r - l + 1 > 3) {  // 当区间足够小时退出
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        
        if (cal(m1, flag) > cal(m2, flag)) {
            l = m1 + 1;
        } else {
            r = m2 - 1;
        }
    }
    for (int i = l; i <= r; ++i) {
        ans = std::min(ans, cal(i, flag));
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
        std::cin >> n >> k;
        ans = inf;
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        std::sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i - 1] + a[i] * (a[i] + 1) / 2;
            count[i] = count[i - 1] + a[i];
        }
        search(2, 1e6 + 1, 0);
        search(1, 1e6, 1);
        std::cout << ans << '\n';
    }

    return 0;
}

// 16 : 39 - 