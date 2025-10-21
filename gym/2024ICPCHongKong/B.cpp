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
const int maxn = 5e5 + 5;
const ll mod = 998244353;
int n, m;
pii e[maxn];
int k;
ll cost[105];
int max_health;
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> m;
        max_health = 0;
        for (int i = 1; i <= n; ++i) {
            std::cin >> e[i].first;
        }
        for (int i = 1; i <= n; ++i) {
            std::cin >> e[i].second;
            max_health = std::max(max_health, e[i].first + e[i].second);
        }
        std::cin >> k;
        for (int i = 1; i <= k; ++i) {
            std::cin >> cost[i];
        }
        ll min = 1e18, count = 0;
        for (int H = max_health; H <= max_health + k - 1; ++H) {
            std::vector<int> bound;
            bound.resize(H + 1);
            for (int i = H; i >= 0; --i) {
                bound[i] = i + k + 1; 
            }
            for (int i = 1; i <= n; ++i) {
                bound[e[i].first - 1] = std::min(H - e[i].second, bound[e[i].first - 1]);
            }
            for (int i = H - 1; i >= 0; --i) {
                bound[i] = std::min(bound[i], bound[i + 1]);
            }

            std::vector<ll> dp[2], ways[2];
            for (int i = 0; i < 2; ++i) {
                dp[i].resize(H + 1, 1e18);
                ways[i].resize(H + 1, 0);
            }
            dp[0][0] = 0;
            ways[0][0] = 1;
            for (int i = 0; i < H; ++i) {
                int limit = bound[i], flag = 0;
                int end = i + k;
                if (end >= limit) flag = 1, end = limit - 1;
                for (int j = i + 1; j <= end; ++j) {
                    int real_j = std::min(j, H);
                    if (dp[0][real_j] > dp[0][i] + cost[j - i]) {
                        dp[0][real_j] = dp[0][i] + cost[j - i];
                        ways[0][real_j] = ways[0][i];
                    } else if (dp[0][real_j] == dp[0][i] + cost[j - i]) {
                        ways[0][real_j] += ways[0][i], ways[0][real_j] %= mod;
                    }
                }

                if (flag) {
                    int real_j = std::min(H, limit);
                    if (dp[1][real_j] > dp[0][i] + cost[limit - i]) {
                        dp[1][real_j] = dp[0][i] + cost[limit - i];
                        ways[1][real_j] = ways[0][i];
                    } else if (dp[1][real_j] == dp[0][i] + cost[limit - i]) {
                        ways[1][real_j] += ways[0][i], ways[1][real_j] %= mod;
                    }
                    end = limit;
                }

                for (int j = i + 1; j <= end; ++j) {
                    int real_j = std::min(j, H);
                    if (dp[1][real_j] > dp[1][i] + cost[j - i]) {
                        dp[1][real_j] = dp[1][i] + cost[j - i];
                        ways[1][real_j] = ways[1][i];
                    } else if (dp[1][real_j] == dp[1][i] + cost[j - i]) {
                        ways[1][real_j] += ways[1][i], ways[1][real_j] %= mod;
                    }
                }

            }
            if (min > dp[1][H]) {
                min = dp[1][H];
                count = ways[1][H];
            } else if (min == dp[1][H]) {
                count += ways[1][H], count %= mod;
            }            
        }
        std::cout << min << ' ' << count << '\n';
    }

    return 0;
}