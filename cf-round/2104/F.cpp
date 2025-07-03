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
ll n;
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
        ll ans = 0, power = 10;
        for (int i = 0; i < 9; ++i) {
            if (i % 2 == 0) ans += n / power * 9;
            if (i % 2 == 0 || n / power == 0) {
                for (int j = 1; j <= 9; ++j) {
                    if (n % power >= power / 10 * j - 1) ++ans;
                    else break;
                }
            } 
            power *= 10;
        }

        std::cout << ans - 1 << '\n';
    }

    return 0;
}
