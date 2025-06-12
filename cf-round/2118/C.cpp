#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <assert.h>
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
ll k;
ll a[maxn];
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
        std::vector<ll> vec;
        int ans = 0;
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= 60; ++j) {
                if ((a[i] & (1ll << j)) == 0) vec.push_back(1ll << j);
                else ans += 1;
            }
        }
        sort(all(vec));
        for (auto it : vec) {
            k -= it;
            if (k < 0) break;
            ans += 1;
        }
        std::cout << ans << '\n';
    }

    return 0;
}
