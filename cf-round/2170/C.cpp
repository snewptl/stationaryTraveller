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
std::set<pli> q, r;
ll n, k;
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
        std::cin >> n >> k;
        q.clear();
        r.clear();
        for (int i = 1; i <= n; ++i) {
            ll x; std::cin >> x;
            q.insert({x, i});
        }
        for (int i = 1; i <= n; ++i) {
            ll x; std::cin >> x;
            r.insert({x, i});
        }        
        int ans = 0;
        while (!q.empty() && !r.empty()) {
            auto it = *q.begin(); q.erase(q.begin());
            pli that = {(k + 1) / (it.first + 1) - 1 + 1, 0};
            auto ptr = r.lower_bound(that);
            if (ptr != r.begin()) {
                --ptr;
                r.erase(ptr);
                ans += 1;
            }
        }
        std::cout << ans << '\n';
        
    }

    return 0;
}
