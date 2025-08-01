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
const int maxn = 5e3 + 5;
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
        int ans = 0;
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        for (int i = n; i >= 1; --i) {
            int count = 0, delta = 0;
            for (int j = 1; j < i; ++j) {
                if (a[j] > a[i]) --delta, ++count;
            }
            for (int j = i + 1; j <= n; ++j) {
                if (a[j] > a[i]) ++delta;
            }
            ans += std::min(delta, 0) + count;
        }
        std::cout << ans << '\n';
    }

    return 0;
}
