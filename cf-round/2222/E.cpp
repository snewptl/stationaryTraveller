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
int n;
int cnt = 0;
int ask(int type, ll x) {
    cnt += 1;
    // if (cnt > n + 3) assert(false);
    if (type == 1) {
        std::cout << "I " << x << std::endl;
    } else {
        std::cout << "Q " << x << std::endl;
    }
    int res;
    std::cin >> res;
    return res;
}
int k;
ll c;
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
        c = 0;
        k = 0;
        cnt = 0;
        std::cin >> n;
        std::cout << (1ll << n) - 1 << std::endl;
        int res = ask(1, (1ll << n) - 1);
        if (res == 1) {
            // & : c == (1 << n) - 1
            // |
            int cur = ask(1, 0);
            if (ask(2, 1) >= 2) {
                // |
                // have (1 << n) - 1 , c
                k = 2;
                ll l = 1, r = (1ll << n) - 2;
                while (l <= r) {
                    ll mid = (l + r) / 2;
                    if (ask(2, mid) >= 2) l = mid + 1, c = mid;
                    else r = mid - 1;
                }
            } else {
                // &
                k = 1;
                c = (1ll << n) - 1;
            }

        } else {
            // & : c != (1 << n) - 1, have (1 << n) - 1 , c
            // ^ :  have (1 << n) - 1 , c ^ ((1 << n) - 1)
            ll l = 1, r = (1ll << n) - 2;
            c = 0;
            while (l <= r) {
                ll mid = (l + r) / 2;
                if (ask(2, mid) >= 2) l = mid + 1, c = mid;
                else r = mid - 1;
            }
            if (c == 0) {
                k = 3;
                c = (1ll << n) - 1;
            } else {
                ask(1, 0);
            // & : c != (1 << n) - 1, have (1 << n) - 1 , c, 0
            // ^ : c != (1 << n) - 1,  have (1 << n) - 1 , c ^ ((1 << n) - 1), c
                if (ask(2, 1) < 3) {
                    k = 1;
                } else {
                    k = 3;
                    c = c ^ ((1ll << n) - 1);
                }
            }
        }
        std::cout << "A " << k << ' ' << c << std::endl;
    }

    return 0;
}
