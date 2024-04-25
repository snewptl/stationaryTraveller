#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 3e5 + 5;
const ll mod = 1e9 + 7;
int n, k;
int r[maxn], c[maxn];
ll dp[maxn];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < maxn; ++i) {
        dp[i] = dp[i - 2] * 2 % mod * (i - 1) % mod + dp[i - 1];
        dp[i] %= mod;
    }

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> k;
        n -= k * 2;
        for (int i = 1; i <= k; ++i) {
            std::cin >> r[i] >> c[i];
            if (r[i] == c[i]) n += 1;
        }
        std::cout << dp[n] << '\n';
    }

    return 0;
}
