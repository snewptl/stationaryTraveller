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
int n, a[maxn];
std::vector<std::vector<int>> vec;
int ind[maxn];
int dp[maxn];
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
        vec.clear();
        vec.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            vec[a[i]].push_back(i);
            ind[i] = vec[a[i]].size() - 1;
        }
        for (int i = 1; i <= n; ++i) {
            dp[i] = 0;
        } 
        for (int i = 0; i < n; ++i) {
            dp[i + 1] = std::max(dp[i], dp[i + 1]);
            int cur = ind[i + 1], next = cur + a[i + 1] - 1;
            if (vec[a[i + 1]].size() > next) {
                int pos = vec[a[i + 1]][next];
                dp[pos] = std::max(dp[pos], dp[i] + a[i + 1]);
            }
        }
        std::cout << dp[n] << '\n';
    }

    return 0;
}
