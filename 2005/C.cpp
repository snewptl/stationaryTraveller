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

const int maxn = 1e3 + 5;
const std::string ch = "narek";

int n, m;
std::string s[maxn];
int dp[6][maxn];

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
        std::cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            std::cin >> s[i];
        }
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j <= n; ++j) {
                dp[i][j] = -1e9;
            }
        }
        dp[0][0] = 0; 
        for (int row = 1; row <= n; ++row) {
            for (int i = 0; i < 5; ++i) {
                dp[i][row] = dp[i][row - 1]; 
            }
            for (int i = 0; i < 5; ++i) {
                if (dp[i][row - 1] == -1e9) continue;
                int wanted = i;
                int add = 0;
                for (int col = 0; col < m; ++col) {
                    if (s[row][col] == ch[wanted]) {
                        if (wanted == 4) add += 5;
                        wanted = (wanted + 1) % 5;
                    } else if (ch.find(s[row][col]) < 5) {
                        --add;
                    }
                }
                dp[wanted][row] = std::max(dp[wanted][row], dp[i][row - 1] + add);
            }
        }
        int ans = 0;
        for (int i = 0; i < 5; ++i) {
            if (dp[i][n] == -1e9) continue;
            ans = std::max(ans, dp[i][n] - i);
        }
        std::cout << ans << '\n';
    }

    return 0;
}
