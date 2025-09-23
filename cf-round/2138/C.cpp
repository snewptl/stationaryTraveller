#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <bitset>
#include <memory.h>
#include <assert.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
const ll mod = 998244353;
int n, k;
std::vector<std::vector<int>> e;
int dep[maxn];
int count[maxn];
int dp[maxn];
int mx_dep;
void dfs(int u) {
    if (e[u].size() == 0) 
        mx_dep = std::min(mx_dep, dep[u]);
    count[dep[u]] += 1;
    for (auto v : e[u]) {
        dep[v] = dep[u] + 1;
        dfs(v);
    }
    
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
        std::cin >> n >> k;
        e.clear();
        e.resize(n + 1);
        mx_dep = n;
        for (int i = 1; i <= n; ++i) {
            dep[i] = 0;
            count[i] = 0;
            dp[i] = 0;
        }
        for (int i = 1; i < n; ++i) {
            int u, v = i + 1;
            std::cin >> u;
            e[u].push_back(v);
        }
        dep[1] = 1;
        dfs(1);
        int del = 0;
        std::map<int, int> mp;
        for (int i = 1; i <= mx_dep; ++i) {
            del += count[i];
            mp[count[i]] += 1;
        }
        dp[0] = 1;
        for (auto [val, num] : mp) {
            std::vector<int> vec;
            while (num > 1) {
                vec.push_back(num / 2 * val);
                num -= num / 2;
            }
            if (num) vec.push_back(num * val);
            for (auto it : vec) {
                for (int i = n; i >= it; --i) {
                    dp[i] |= dp[i - it];
                }
            }
        }
        int l = std::max(k - (n - del), 0), r = k, flag = 0;
        for (int i = l; i <= r; ++i) {
            flag |= dp[i];
        }
        int ans = flag + mx_dep - 1;
        std::cout << ans << '\n';
    }

    return 0;
}
