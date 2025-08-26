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
int n, a[maxn];
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
            std::cin >> a[i];
        }
        int fin = 0;
        for (int i = 1; i < n; ++i) {
            int ans = 2;
            int l = i, r = n;
            while (l < r) {
                int min = a[l], max = a[r];
                if (min == max) {
                    ans += r - l - 1;
                    break;
                }
                auto it = std::upper_bound(a + l, a + r, (min + max) / 2) - a;
                --it;
                if (it > l) {
                    ans += 1;
                    r = it;
                } else {
                    break;
                }
            }
            fin = std::max(ans, fin);
        }
        std::cout << n - fin << '\n';
    }

    return 0;
}
// 19 : 00 - 19 : 39 