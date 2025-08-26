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
const int maxn = 5e5 + 5;
const ll mod = 998244353;
int n;
ll a[maxn];
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
        ll min = 1e9;
        ans = 0;
        int count[2] = {0, 0};
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            if (a[i] >= 0) count[1] += 1;
            else count[0] += 1;
            ans += abs(a[i]);
            min = std::min(min, std::abs(a[i]));
        }
        if ((count[0] == 0 || count[1] == 0)) {
            ans -= min * 2;
        }
        if (n == 1) ans = a[1];
        std::cout << ans << '\n';
    }

    return 0;
}
