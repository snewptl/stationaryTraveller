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
int n, a[maxn], vis[maxn], sum[maxn];
std::vector<std::vector<int>> vec;
ll dp[maxn], ans;
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        vis[a[i]] = 1;
    }
    int mx = 3e5;
    for (int i = 1; i <= mx; ++i) {
        sum[i] = sum[i - 1] + vis[i];
    }
    vec.resize(mx + 1);
    for (int i = 2; i <= mx; ++i) {
        for (int j = i; j <= mx; j += i) {
            if (vis[j]) {
                vec[i].push_back(j);
            }
        }
        dp[i] = -1;
    }
    ans = 1ll * n * (n - 1) * (n - 2) / 6;
    for (int i = 2; i <= mx; ++i) {
        ll tot = 0;
        for (auto it : vec[i]) {
            tot += sum[it];
        }
        for (int j = 0; j < vec[i].size(); ++j) {
            tot -= sum[vec[i][j]];
            ans += (tot - 1ll * (sum[vec[i][j]] + 1) * (vec[i].size() - j - 1)) * dp[i];
        }
        for (int j = i * 2; j <= mx; j += i) {
            dp[j] -= dp[i]; 
        }
    }
    std::cout << ans << '\n';
    return 0;
}
// 9 : 40 - 10 : 23