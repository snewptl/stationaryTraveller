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
ll a[maxn], b[maxn];
int n;
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
        for (int i = 1; i <= n; ++i) {
            std::cin >> b[i];
        }
        ll min = 0, max = 0;
        for (int i = 1; i <= n; ++i) {
            ll temp_min = std::min(min - a[i], b[i] - max);
            ll temp_max = std::max(b[i] - min, max - a[i]);
            min = temp_min;
            max = temp_max;
        }
        std::cout << max << '\n';
    }

    return 0;
}
