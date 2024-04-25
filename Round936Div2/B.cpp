#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const ll mod = 1e9 + 7;
const int maxN = 2e5 + 5;
int n, k, a[maxN];
ll prefix[maxN];
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        ll mn = 0, base = 0;
        for (int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i - 1] + a[i];
            mn = std::min(mn, prefix[i]);
            base = std::max(base, prefix[i] - mn);
        }
        ll ans = 0;
        for (int i = 1; i <= k; ++i) {
            ans += base, ans %= mod;
            base *= 2;
            base %= mod;
        }
        for (int i = 1; i <= n; ++i) {
            ans += a[i], ans %= mod;
        }
        std::cout << (ans + mod) % mod << '\n';

    }

    return 0;
}
