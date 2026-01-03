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
ll x, y, k;
bool check(ll max) {
    ll time = x;
    while (max >= y && max >= k && time) {
        ll cur = max / y;
        
        if (cur >= y) {
            time -= 1;
            max -= cur;
        } else {
            
            ll to = cur * y - 1;
            ll temp = (max - to + cur - 1) / cur;
            temp = std::min(temp, time);
            ll del = temp * cur;
            max -= del;
            if (cur * time + k <= max) return true;
            time -= temp;
        }
    }

    if (max >= k) return true;
    return false;
    
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> x >> y >> k;
        ll l = 1, r = 1e12, ans = -1;
        while (l <= r) {
            ll mid = (l + r) / 2;
            if (check(mid)) {
                r = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }
        std::cout << ans << '\n';
    }

    return 0;
}
