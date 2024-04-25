#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 1e3 + 5;
int n, k;
int a[maxn][maxn];
std::vector<int> dp[maxn];
struct Node {
    int val;
    int row, column;
    bool operator<(const Node& other) const { return val < other.val; }
};
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                std::cin >> a[i][j];
            }
        }
        dp[0].push_back(0);
        for (int i = 1; i <= n; ++i) {
            std::priority_queue<Node> q;
            for (int j = 0; j <= i - 2; ++j) {
                q.push({dp[j][0] + a[j + 2][i], 0, j});
            }
            q.push({dp[i - 1][0], 0, i - 1});
            q.push({a[1][i], 0, 0});
            int size = 0;
            while (!q.empty() && size < k) {
                auto it = q.top();
                q.pop();
                dp[i].push_back(it.val);
                if (it.row + 1 < dp[it.column].size()) {
                    if (it.column != i - 1) {
                        q.push({dp[it.column][it.row + 1] + a[it.column + 2][i],
                                it.row + 1, it.column});
                    } else {
                        q.push({dp[i - 1][it.row + 1], it.row + 1, i - 1});
                    }
                }
                ++size;
            }
        }
        for (int i = 0; i < k; ++i)
            std::cout << dp[n][i] << ' ';
        std::cout << '\n';

        for (int i = 0; i <= n; ++i)
            dp[i].clear();
    }

    return 0;
}