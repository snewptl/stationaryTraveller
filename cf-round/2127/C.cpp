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
std::set<pll> rl;
std::map<ll, int> mp;
int n, k;
ll a[maxn], b[maxn], sum;
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
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        for (int i = 1; i <= n; ++i) std::cin >> b[i];
        rl.clear();
        mp.clear();
        sum = 0;
        ll delta = 2e9;
        for (int i = 1; i <= n; ++i) {
            int x = a[i], y = b[i];
            if (x > y) std::swap(x, y);
            rl.insert({y, x});
            if (mp.count(y)) delta = 0;
            mp[y] = 1;
            sum += y - x;
        }
        for (int i = 1; i <= n; ++i) {
            int x = a[i], y = b[i];
            if (x > y) std::swap(x, y);
            auto it = rl.lower_bound({y, x});
            if (it == rl.begin()) continue;
            --it;
            auto [new_y, new_x] = *it;
            if (new_y >= x) delta = 0;
            else delta = std::min(delta, (x - new_y) * 2);
        }
        std::cout << delta + sum << '\n';

    }

    return 0;
}
