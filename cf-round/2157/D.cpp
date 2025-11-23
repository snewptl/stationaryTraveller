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
int n, l, r, a[maxn];
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
        std::cin >> n >> l >> r;
        ll sum = 0;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            if (a[i] > r) sum += a[i] - r, a[i] = r;
            else if (a[i] < l) sum += l - a[i], a[i] = l;
        }
        std::sort(a + 1, a + n + 1);
        for (int i = 1, j = n; i < j; ++i, --j) {
            sum += a[j] - a[i];
        }
        std::cout << sum << '\n';
        
    }

    return 0;
}
