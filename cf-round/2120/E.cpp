#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <bitset>
#include <memory.h>
#include <assert.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
const ll mod = 998244353;
int n;
ll k;
int a[maxn];
bool check(int x) {
    ll count = 0, need = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] < x) need += x - a[i];
        else if (a[i] >= x + k) count += a[i] - (x + k - 1);
    }
    return count >= need;
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
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        int l = 1, r = 1e6;
        ll min = 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(mid)) l = mid + 1, min = mid;
            else r = mid - 1;
        }
        ll ans = 0;
        std::sort(a + 1, a + n + 1);
        ll count1 = 0, count2 = 0;
        for (int i = n; i >= 1; --i) {
            if (a[i] >= min + k) count1 += a[i] - (min + k), count2 += 1, a[i] = min + k - 1;
            else if (a[i] < min) {
                ll delta = min - a[i];
                ll temp = std::min(count1, delta);
                count1 -= temp;
                delta -= temp;
                ans += temp * k;
                if (delta) {
                    ll temp = std::min(count2, delta);
                    count2 -= temp;
                    delta -= temp;
                    ans += temp * k;
                }
                a[i] = min;
            } 
            ans += 1ll * a[i] * (a[i] + 1) / 2;
        }
        ans += (min + k + 1) * count1;
        ans += (min + k) * count2;
        std::cout << ans << '\n';
        
        
    }

    return 0;
}
