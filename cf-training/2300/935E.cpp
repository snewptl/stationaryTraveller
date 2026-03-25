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
std::string s;
int p, m;
int min_sgn, count;
struct node {
    int dp[2][101];
    int len;
    node (int len) {
        this->len = len;
        for (int i = 0; i <= std::min(count, len); ++i) {
            dp[0][i] = -1e9;
            dp[1][i] = 1e9;
        }
    }
};
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    // std::cin >> T;
    while (T--) {
        std::cin >> s >> p >> m;
        count = std::min(p, m);
        if (p > m) min_sgn = 1;
        else min_sgn = 0;
        std::vector<node> vec;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ')') {
                auto right = vec.back(); vec.pop_back();
                auto left = vec.back(); vec.pop_back();
                node res(left.len + right.len + 1);
                
                for (int i = 0; i <= std::min(left.len, count); ++i) {
                    for (int j = 0; j <= std::min(right.len, count - i); ++j) {
                        if (left.len + right.len - (i + j) > std::max(p, m)) continue;
                        if (min_sgn == 0) {
                            if (i + j + 1 <= count) {
                                res.dp[0][i + j + 1] = std::max(res.dp[0][i + j + 1], left.dp[0][i] + right.dp[0][j]);
                                res.dp[1][i + j + 1] = std::min(res.dp[1][i + j + 1], left.dp[1][i] + right.dp[1][j]);
                            }
                            if (left.len + right.len - (i + j) + 1 <= std::max(p, m)) {
                                res.dp[0][i + j] = std::max(res.dp[0][i + j], left.dp[0][i] - right.dp[1][j]);
                                res.dp[1][i + j] = std::min(res.dp[1][i + j], left.dp[1][i] - right.dp[0][j]);
                            }
                        } else {
                            if (i + j + 1 <= count) {
                                res.dp[0][i + j + 1] = std::max(res.dp[0][i + j + 1], left.dp[0][i] - right.dp[1][j]);
                                res.dp[1][i + j + 1] = std::min(res.dp[1][i + j + 1], left.dp[1][i] - right.dp[0][j]);
                            }
                            if (left.len + right.len - (i + j) + 1 <= std::max(p, m)) {
                                res.dp[0][i + j] = std::max(res.dp[0][i + j], left.dp[0][i] + right.dp[0][j]);
                                res.dp[1][i + j] = std::min(res.dp[1][i + j], left.dp[1][i] + right.dp[1][j]);
                            }
                        }
                    }
                }
                vec.push_back(res);
            } else {
                if (s[i] <= '9' && s[i] >= '0') {
                    node temp(0);
                    temp.dp[0][0] = temp.dp[1][0] = s[i] - '0';
                    vec.push_back(temp);
                }
            }
        }
        int ans;
        if (min_sgn == 0) {
            ans = vec.back().dp[0][p];
        } else {
            ans = vec.back().dp[0][m];
        }
        std::cout << ans << '\n';
    }

    return 0;
}
// 11 : 38 - 