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
ll dp[20][10];
ll p10[20];
ll C[11][11], sum[10];
ll dfs(int r, int dep, int flag, int used) {
    if (dep) {
        ll digit = r / p10[dep];
        r -= digit * p10[dep];
        for (int i = 0; i < digit) {
            dfs(r, dep - 1, 0, )
        }
    } else {

    }
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
        p10[i] = p10[i - 1] * 10 % mod;
    }
    C[1][0] = C[1][1] = 1;
    for (int i = 2; i <= 10; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = C[i][j - 1] + C[i - 1][j - 1];
            C[i][j] %= mod;
        }
    }
    for (int i = 1; i <= 10; ++i) {
        sum[i] = sum[i - 1] * (10 - (i - 1)) % mod;
        for (int j = 0; j <= 9; ++j) {
            sum[i] += C[10 - 1][i - 1] * i % mod;
            sum[i] %= mod;
        }
    }
    
    std::cin >> l >> r >> k;
    std::cout << (dfs(r, 17, 1, 0) - dfs(l - 1, 17, 1, 0) + mod) % mod << '\n';
    return 0;
}
// 10 : 26 - 