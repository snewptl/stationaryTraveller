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
int count[maxn];
bool check(int x) {
    std::set<pii> s;
    for (int i = 0; i < x; ++i) {
        count[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] >= x) s.insert({(a[i] - 1) / 2, i});
        else {
            if (!count[a[i]]) count[a[i]] = 1;
            else s.insert({(a[i] - 1) / 2, i});
        }
    }
    for (int i = 0; i < x; ++i) {
        if (count[i]) continue;
        int cur = -1;
        while (!s.empty()) {
            auto [val, _] = *s.begin();
            s.erase(s.begin());
            cur = val;
            if (cur >= i) break;
        }
        if (cur >= i) count[i] = 1;
        if (!count[i]) return false;
    }
    return true;
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
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        int l = 0, r = n, ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
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
