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
const int maxn = 3e5 + 5;
const ll mod = 998244353;
int n, k, a[maxn], b[maxn];
pii seg;
bool check_left(int x) {
    for (int i = 1; i <= n; ++i) {
        if (a[i] <= x) b[i] = 1;
        else b[i] = -1;
    }
    for (int i = 1; i <= n; ++i) {
        b[i] += b[i - 1];
    }
    std::set<int> s;
    s.insert(0);
    for (int i = k; i <= n; ++i) {
        if (b[i] >= *s.begin()) {
            return true;
        }
        s.insert(b[i - k + 1]);
    }
    return false;
}
bool check_right(int x) {
    for (int i = 1; i <= n; ++i) {
        if (a[i] >= x) b[i] = 1;
        else b[i] = -1;
    }
    for (int i = 1; i <= n; ++i) {
        b[i] += b[i - 1];
    }
    std::set<int> s;
    s.insert(0);
    for (int i = k; i <= n; ++i) {
        if (b[i] >= *s.begin()) {
            return true;
        }
        s.insert(b[i - k + 1]);
    }
    return false;
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
        std::cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        int l = 1, r = n, ans = 0;
        pii seg = {0, 0};
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check_left(mid)) {
                if (check_right(mid)) {
                    ans = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            } else {
                l = mid + 1;
            }
        }
        std::cout << ans << '\n';
    }

    return 0;
}
