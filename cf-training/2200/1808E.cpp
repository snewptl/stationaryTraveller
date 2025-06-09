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
ll mod = 998244353;
int n, k;
ll dp[105][35];
ll except[35][105][35], double_ex[35][105][35];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    
    std::cin >> n >> k >> mod;
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < k; ++j) {
            for (int cur = 0; cur < k; ++cur) {
                dp[i][j] += dp[i - 1][(j - cur + k) % k];
                dp[i][j] %= mod;
            }   
        }
    }
    ll ans = 0;
    int end = k;
    if (k % 2 == 0) end /= 2;
    for (int i = 0; i < end; ++i) ans += dp[n][i], ans %= mod;
    if (k % 2) {
        for (int ex = 0; ex < k; ++ex) except[ex][0][0] = 1;
        for (int ex = 0; ex < k; ++ex) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 0; j < k; ++j) {
                    for (int cur = 0; cur < k; ++cur) {
                        if (cur == ex) continue;
                        except[ex][i][j] += except[ex][i - 1][(j - cur + k) % k];
                        except[ex][i][j] %= mod;
                    }   
                }
            }
        }
        for (int ex = 0; ex < k; ++ex) ans -= except[ex][n][ex * 2 % k], ans %= mod;
    } else {
        for (int ex = 0; ex < k / 2; ++ex) double_ex[ex][0][0] = 1;
        for (int ex = 0; ex < k / 2; ++ex) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 0; j < k; ++j) {
                    for (int cur = 0; cur < k; ++cur) {
                        if (cur == ex || cur == ex + k / 2) continue;
                        double_ex[ex][i][j] += double_ex[ex][i - 1][(j - cur + k) % k];
                        double_ex[ex][i][j] %= mod;
                    }   
                }
            }
        }
        for (int ex = 0; ex < k / 2; ++ex) ans -= double_ex[ex][n][ex * 2 % k], ans %= mod;
    }
    std::cout << (ans + mod) % mod << '\n';

    return 0;
}
