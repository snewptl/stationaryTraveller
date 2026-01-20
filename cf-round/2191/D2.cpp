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
int n;
std::string s;
ll way[101][101][102], len[101][101][102];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--){
        std::cin >> n >> s;
        for (int i = 0; i <= 100; ++i) {
            for (int j = 0; j <= 100; ++j) {
                for (int k = 0; k <= 101; ++k) {
                    way[i][j][k] = 0;
                    len[i][j][k] = 0;
                }
            }
        }
        way[0][0][101] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= 100; ++j) {
                for (int k = 0; k <= 101; ++k) {
                    way[i][j][k] = way[i - 1][j][k];
                    len[i][j][k] = len[i - 1][j][k];
                } 
            }
            if (s[i - 1] == '(') {
                for (int j = 100; j >= 1; --j) {
                    for (int k = 1; k <= 100; ++k) {
                        way[i][j][k] += way[i - 1][j - 1][k - 1];
                        way[i][j][k] %= mod;
                        len[i][j][k] += len[i - 1][j - 1][k - 1] + way[i - 1][j - 1][k - 1];
                        len[i][j][k] %= mod;
                    }
                    way[i][j][101] += way[i - 1][j - 1][101];
                    way[i][j][101] %= mod;
                    len[i][j][101] += len[i - 1][j - 1][101] + way[i - 1][j - 1][101];
                    len[i][j][101] %= mod;
                }
            } else {
                for (int j = 0; j < 100; ++j) {
                    for (int k = 0; k <= 100; ++k) {
                        way[i][j][k] += way[i - 1][j + 1][k];
                        way[i][j][k] %= mod;
                        len[i][j][k] += len[i - 1][j + 1][k] + way[i - 1][j + 1][k];
                        len[i][j][k] %= mod;
                    }
                    way[i][j][0] += way[i - 1][j + 1][101];
                    way[i][j][0] %= mod;
                    len[i][j][0] += len[i - 1][j + 1][101] + way[i - 1][j + 1][101];
                    len[i][j][0] %= mod;
                }
            }
        }
        ll ans = 0;
        for (int i = 2; i <= 100; ++i) {
            ans += len[n][0][i];
            ans -= way[n][0][i] * 2 % mod;
            ans = (ans % mod + mod) % mod;
        }
        std::cout << ans << '\n';
    }

    return 0;
}
