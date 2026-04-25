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
const int maxn = 5e3 + 5;
const ll mod = 998244353;
int n;
int a[maxn];
int dp[maxn];
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
        std::cin >> n;
        std::vector<int> vec;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            vec.push_back(a[i]);
        }
        std::sort(all(vec));
        int mid = vec[(n - 1) / 2];
        for (int i = 1; i <= n; ++i) {
            dp[i] = -1e9;
        }
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            int l = 0, r = 0, eq = 0;
            for (int j = i - 1; j >= 0; --j) {
                if (a[j + 1] < mid) l += 1;
                else if (a[j + 1] > mid) r += 1;
                else eq += 1;
                int half = (i - j + 1) / 2;
                if (eq + l >= half && eq + r >= half && (i - j) % 2) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }
        std::cout << dp[n] << '\n';
    }

    return 0;
}
