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
int n, p;
ll a[maxn];
void solve() {
    std::map<int, int> mp, prefix;
    for (int i = 1; i <= n; ++i) {
        mp[a[i]] += 1;
    }
    ll sum = 0;
    for (auto [key, val] : mp) {
        pll seg1, seg2;
        seg1.first = std::max(key - sum, 0ll);
        sum += val;
        seg1.second = std::max(std::min(p - 1 + key - sum, key * 1ll), -1ll);
        // if (seg.first > seg.second) continue;
        seg2 = {key, 1e9};
        if (sum >= p) seg2.first = 1e9 + 1;
        if (seg1.first <= seg1.second) {
            prefix[seg1.first] += val;
            prefix[seg1.second + 1] -= val;
            if (seg2.first <= seg2.second && seg2.second >= seg1.first && seg2.first <= seg1.second) {
                if (seg2.first < seg1.first) {
                    prefix[seg2.first] += val;
                    prefix[seg1.first] -= val;
                }
                if (seg2.second > seg1.second) {
                    prefix[seg1.second + 1] += val;
                    prefix[seg2.second + 1] -= val;
                }
            }
        } else if (seg2.first <= seg2.second) {
            prefix[seg2.first] += val;
            prefix[seg2.second + 1] -= val;
        }
    }
    ll count = 0, last = 0;
    std::vector<int> vec;
    for (auto [key, val] : prefix) {
        count += val;
        if (count == n) {
            if (!last) last = key;
        } else {
            if (last) {
                for (int i = last; i < key; ++i) vec.push_back(i);
                last = 0;
            }
        }
    }
    std::cout << vec.size() << '\n';
    for (auto it : vec) std::cout << it << ' ';
    std::cout << '\n';
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> p;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    solve();
    

    return 0;
}
// 17 : 10 -         