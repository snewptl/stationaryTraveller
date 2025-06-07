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
std::bitset<200001> dp, mask; 
ll sum[maxn];
ll ans;
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    // std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];  
            sum[i] = sum[i - 1] + a[i]; 
        }
        ans = 0;
        dp.reset();
        dp.set(1);
        mask.set();
        mask <<= 1;
        for (int i = 1; i <= n * 2; ++i) {
            if (i <= n) dp |= dp << a[i];
            if ((dp & mask).test(i)) {
                ans = std::max(ans, sum[(i > n ? n : i)] - i + 1);
            }
            dp.reset(i);
            mask.reset(i);
        }
        std::cout << ans << '\n';
    }

    return 0;
}
