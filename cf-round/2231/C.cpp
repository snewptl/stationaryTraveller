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
int a[maxn];
std::map<int, int> mp;
std::set<int, std::greater<int>> s;
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
        std::cin >> n;
        mp.clear();
        s.clear();
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            s.insert(a[i]);
            mp[a[i]] += 1;
        }
        ll ans = 0;
        while (s.size() > 1) {
            auto it = *s.begin();
            s.erase(it);
            auto that = *s.begin();
            if (it == 2) {
                ans += std::min(mp[1], mp[2]);
                break;
            }
            if (that % 2 && that + 1 == it) {
                s.insert(it);
                it = that;
                s.erase(it);
            }
            int last = mp[it];
            mp[it] = 0;
            if (it % 2) {
                it += 1;
            } else {
                it /= 2;
            }
            s.insert(it);
            mp[it] += last;
            ans += last;
        }
        std::cout << ans << '\n';
    }

    return 0;
}
