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
int k, n;
int a[maxn];
ll sum[maxn];
int count[maxn];
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
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            count[i] = 0;
        }
        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i - 1] + a[i];
        }
        count[0] = 1;
        for (int i = 1; i <= n; ++i) {
            if (i + k > n) break;
            ans += count[sum[i + k] % k];
            count[sum[i] % k] += 1;
        }
        std::cout << ans << '\n';
    }

    return 0;
}
