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
ll l, r;
int k;
ll p10[20], pk[20], prefix10[20];
ll dp[20][10];
ll C[10][10];
std::vector<ll> count(10, 0);
int digit_sum() {
    int res = 0;
    for (int i = 1; i <= 9; ++i) {
        if (count[i]) res += 1;
    }
    if (!res) return res;
    return res + count[0];
}
void try_update(int pos, int delta) {
    if (pos != 0) count[pos] += delta;
    else {
        if (digit_sum()) {
            count[pos] += delta;
        }
    }
}
ll solve(ll x) {
    ll ans = 0, sum = 0;
    count.clear();
    count.resize(10, 0);
    for (int i = 17; i >= 0; --i) {
        int cur = l / p10[i];
        for (int j = 0; j < cur; ++j) {
            try_update(j, 1);
            sum += j * p10[i] % mod;
            sum %= mod;
            if (digit_sum() <= k) {
                for (int t = 0; t <= 9; ++t) {
                    ans += pk[i] * sum % mod;
                    ans %= mod;
                }
                if (i) {
                    for (int t = 1; t <= 9; ++t) {
                        ans += pk[i - 1] * prefix10[i] % mod * t % mod;
                        ans %= mod;
                    }
                }
            }
            try_update(j, -1);
            sum -= j * p10[i] % mod;
            sum = (sum + mod) % mod;
        }
        try_update(cur, 1);
        sum += cur * p10[i];
    }
    if (digit_sum() <= k) ans += x, ans %= mod;
    return ans;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    p10[0] = 1;
    for (int i = 1; i < 18; ++i) {
        p10[i] = p10[i - 1] * 10;
    }
    for (int i = 0; i < 18; ++i) {
        prefix10[i] = p10[i];
        if (i) {
            prefix10[i] += prefix10[i - 1];
        }
        prefix10[i] %= mod;
    }
    pk[0] = 1;
    for (int i = 1; i < 18; ++i) {
        pk[i] = pk[i - 1] * k % mod;
    }
    
    std::cin >> l >> r >> k;
    std::cout << (solve(r) - solve(l - 1) + mod) % mod << '\n';
    return 0;
}
// 10 : 26 - 