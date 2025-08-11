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
const int maxn = 3e5 + 5;
const ll mod = 998244353;
int n, m;
pii a[maxn], b[maxn];
std::vector<pii> stack_a, stack_b;
int dp[2][maxn], vis[2][maxn];
int count[4];
int dfs(int defend, int side, int idx) {
    if (idx != -1) {
        if (dp[side][idx]) return dp[side][idx];
        if (vis[side][idx]) return dp[side][idx] = 2;
    }
    int res;
    if (idx != -1) vis[side][idx] = 1;
    int new_side = side ^ 1;
    if (new_side == 0) {
        auto it = std::lower_bound(all(stack_a), std::make_pair(defend + 1, 0));
        if (it == stack_a.end()) {
            res = 3;
        } else {
            int new_idx = it - stack_a.begin();
            int new_defend = stack_a[new_idx].second;
            res = dfs(new_defend, new_side, new_idx);
        }
    } else {
        auto it = std::lower_bound(all(stack_b), std::make_pair(defend + 1, 0));
        if (it == stack_b.end()) {
            res = 1;
        } else {
            int new_idx = it - stack_b.begin();
            int new_defend = stack_b[new_idx].second;
            res = dfs(new_defend, new_side, new_idx);
        }
    }
    if (idx != -1) vis[side][idx] = 0, dp[side][idx] = res;
    return res;
}
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
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i].first;
        }
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i].second;
        }        
        std::cin >> m;
        for (int i = 1; i <= m; ++i) {
            std::cin >> b[i].first;
        }
        for (int i = 1; i <= m; ++i) {
            std::cin >> b[i].second;
        }
        std::sort(a + 1, a + n + 1);
        std::sort(b + 1, b + m + 1);
        count[1] = count[2] = count[3] = 0;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j <= std::max(m, n); ++j) {
                dp[i][j] = 0;
                vis[i][j] = 0;
            }
        }
        stack_a.clear();
        for (int i = 1; i <= n; ++i) {
            while (!stack_a.empty()) {
                if (stack_a.back().second < a[i].second) stack_a.pop_back();
                else break;
            }
            if (stack_a.empty() || stack_a.back().first != a[i].first) stack_a.push_back(a[i]);
        }
        stack_b.clear();
        for (int i = 1; i <= m; ++i) {
            while (!stack_b.empty()) {
                if (stack_b.back().second < b[i].second) stack_b.pop_back();
                else break;
            }
            if (stack_b.empty() || stack_b.back().first != b[i].first) stack_b.push_back(b[i]);
        }
        for (int i = 1; i <= n; ++i) {
            count[dfs(a[i].second, 0, -1)] += 1;
        }
        for (int i = 1; i <= 3; ++i) {
            std::cout << count[i] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
// 19 : 25 - 20 : 25