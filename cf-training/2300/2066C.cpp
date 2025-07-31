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
const ll mod = 1e9 + 7;
int n, a[maxn];
std::map<int, ll> dp;
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
        dp.clear();
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        dp[0] = 1;
        int xor_sum = 0;
        for (int i = 1; i <= n; ++i) {
            if (dp.count(xor_sum)) {
                dp[xor_sum] += 2 * dp[xor_sum];
                dp[xor_sum] %= mod;
            }
            if (dp.count(xor_sum ^ a[i])) {
                dp[xor_sum] += dp[xor_sum ^ a[i]] * 2;
                dp[xor_sum] %= mod;
            }
            xor_sum ^= a[i];
        }
        ll ans = 0;
        for (auto it : dp) {
            ans += it.second;
            ans %= mod;
        }
        std::cout << ans << '\n';
    }

    return 0;
}
// 11 : 53 - 12 : 40

// a b b 
/*
A B B 

A^a B B 
A B^a B :

1. B = A
2. B = A^a

*/