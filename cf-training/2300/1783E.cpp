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
int dp[maxn];
int n, a[maxn], b[maxn]; 
int end(int x, int k) {
    if (k == 0) return n; 
    return x / k;
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
            std::cin >> a[i];
            --a[i];
        }
        for (int i = 1; i <= n; ++i) {
            std::cin >> b[i];
            --b[i];
        }
        for (int i = 1; i <= n + 1; ++i) {
            dp[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            int j = a[i] - b[i] + 1; 
            if (a[i] <= b[i]) {
                dp[1] += 1;
                continue;
            }
            while (j <= n) {
                int temp1 = a[i] / j, temp2 = b[i] / j; 
                int l = j, r = std::min(end(a[i], temp1), end(b[i], temp2));
                r = std::min(r, n);
                if (temp1 <= temp2) {
                    dp[l] += 1;
                    dp[r + 1] -= 1;
                }
                j = r + 1;
            }
        }
        std::vector<int> res;
        for (int i = 1; i <= n; ++i) {
            dp[i] += dp[i - 1];
            if (dp[i] >= n) res.push_back(i);
        }
        std::cout << res.size() << '\n';
        for (auto it : res) std::cout << it << ' ';
        std::cout << '\n';

    }

    return 0;
}
// 22 : 23 - 
