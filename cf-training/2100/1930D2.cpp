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
const int maxn = 1e6 + 5;
int n;
std::string str;
int dp[2][maxn];
ll sum[maxn];
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
        std::cin >> n >> str;
        ll ans = 0;
        if (str[n - 1] == '1') {
            if (n >= 2) {
                dp[1][n - 2] = 1;
                dp[0][n - 2] = 0;
            }
            ++ans;
        } else {
            if (n >= 2) {
                dp[1][n - 2] = 0;
                dp[0][n - 2] = 1;
            }
        }
        sum[n - 1] = 0;
        for (int i = n - 2; i >= 0; --i) {
            sum[i] = sum[i + 1] + dp[1][i];
            if (str[i] == '1') {
                if (i) {
                    dp[1][i - 1] = dp[0][i] + 1;
                    dp[0][i - 1] = dp[1][i];
                }
                ans += sum[i + 1] + (n - i - dp[1][i + 1]);
            } else {
                if (i) {
                    dp[1][i - 1] = 0;
                    dp[0][i - 1] = dp[1][i] + dp[0][i] + 1;
                }
                ans += sum[i + 1] + dp[1][i];
            } 
        }
        std::cout << ans << '\n';
    }

    return 0;
}
