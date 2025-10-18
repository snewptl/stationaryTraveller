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
ll x[maxn];
pll a[maxn];
std::vector<pli> neg, pos;
bool check(ll val) {
    std::set<pli> s_neg, s_pos;
    for (auto it : neg) s_neg.insert(it);
    for (auto it : pos) s_pos.insert(it);
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i].first == 0) {
            if (val <= a[i].second) ++count;
        }
        else if (a[i].first < 0) { // neg
            ll cur = (val - a[i].second) / a[i].first;
            if ((a[i].second - val) % (-a[i].first)) {
                if (val - a[i].second > 0) cur -= 1;
            }
            auto it = s_neg.upper_bound({cur, n + 1});
            if (it != s_neg.begin()) {
                --it;
                s_neg.erase(it);
                ++count;
            }
        } else {
            ll cur = (val - a[i].second) / a[i].first;
            if ((val - a[i].second) % a[i].first) {
                if (val - a[i].second > 0) cur += 1;
            }
            auto it = s_pos.lower_bound({cur, 0});
            if (it != s_pos.end()) {
                s_pos.erase(it);
                ++count;
            }
        }
    }
    return count >= (n + 1) / 2;
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
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i].first;
        }
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i].second;
        }
        for (int i = 1; i <= n; ++i) {
            std::cin >> x[i];
        }
        neg.clear();
        pos.clear();
        std::sort(x + 1, x + n + 1);
        std::sort(a + 1, a + n + 1);
        int count_neg = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i].first <= 0) {
                ++count_neg;
            }
        }
        for (int i = 1; i <= count_neg; ++i) {
            neg.push_back({x[i], i});
        }
        for (int i = count_neg + 1; i <= n; ++i) {
            pos.push_back({x[i], i});
        }
        ll l = -2e18, r = 2e18, ans = -2e18;
        while (l <= r) {
            ll mid = (l + r) / 2; 
            if (check(mid)) {
                l = mid + 1;
                ans = mid;
            } else {
                r = mid - 1;
            }
        }
        std::cout << ans << '\n';
        
    }

    return 0;
}
