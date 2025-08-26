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
int n, a[maxn];
std::set<pii, std::greater<pii>> s;
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
        s.clear();
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            s.insert({a[i], i});
        }
        ll ans = 0;
        while (s.size() >= 2) {
            auto it = *s.begin();
            s.erase(it);
            auto that = *s.begin();
            s.erase(that);
            ans += std::max(it.first, that.first);
        }
        if (s.size() == 1) ans += s.begin()->first;
        std::cout << ans << '\n';
    }

    return 0;
}
