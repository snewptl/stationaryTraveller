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
const int maxn = 3e5 + 5;
const ll mod = 998244353;
int l, r, n;
int a[maxn];
std::vector<pii> seg;
bool is_out(int x) {
    return x > r || x < l;
}
void dfs(int bit, int val, int x, int ori) {
    if (bit < 0) {
        return;
    }
    x ^= (1 << bit) & ori;
    if ((val | ((1 << bit) - 1)) >= l) {
        if (!is_out(val) && !is_out(val | ((1 << bit) - 1))) {
            seg.push_back({x, x | ((1 << bit) - 1)});
        } else {
            dfs(bit - 1, val, x, ori);
        }
    } 
    if ((val | (1 << bit)) <= r) {
        if (!is_out((val | (1 << bit))) && !is_out(val | ((1 << (bit + 1)) - 1))) {
            seg.push_back({x ^ (1 << bit), x ^ (1 << bit) | ((1 << bit) - 1)});
        } else {
            dfs(bit - 1, val | (1 << bit), x ^ (1 << bit), ori);
        }
    }
}
int solve() {
    std::sort(all(seg));
    std::map<int, int> mp;
    int count = 0;
    for (auto [l, r] : seg) {
        mp[l] += 1;
        mp[r + 1] -= 1; 
    }
    int last = 0;
    for (auto [cur, cnt] : mp) {
        last += cnt;
        if (last == n) {
            return cur;
        }
    }
    return 0; 
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
        std::cin >> l >> r;
        n = r - l + 1;
        seg.clear();
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            dfs(16, 0, 0, a[i]);
        }
        std::cout << solve() << '\n';
    }

    return 0;
}
// 12 : 25 - 