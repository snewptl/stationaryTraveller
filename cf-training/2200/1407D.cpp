#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <assert.h>
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
int n, h[maxn], dp[maxn];
int mx[maxn][20], mn[maxn][20];
int find_min(int l, int r) {
    if (l > r) return 1e9;
    int cur = r, res = 1e9;
    for (int j = 19; j >= 0; --j) {
        if (cur - (1 << j) >= l) {
            res = std::min(res, mn[cur][j]);
            cur -= (1 << j);
        }
    }
    res = std::min(res, h[l]);
    return res;
}
int find_max(int l, int r) {
    if (l > r) return 0;
    int cur = r, res = 0;
    for (int j = 19; j >= 0; --j) {
        if (cur - (1 << j) >= l) {
            res = std::max(res, mx[cur][j]);
            cur -= (1 << j);
        }
    }
    res = std::max(res, h[l]);
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
    // std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) std::cin >> h[i];
        std::vector<int> inc, dec;
        for (int i = 1; i <= n; ++i) dp[i] = 1e9;
        for (int j = 0; j < 20; ++j) {
            for (int i = 1; i <= n; ++i) {
                mx[i][j] = 0;
                mn[i][j] = 1e9;
            }
        }
        for (int i = 1; i <= n; ++i) {
            mx[i][0] = h[i];
            mn[i][0] = h[i];
        }
        for (int j = 1; j < 20; ++j) {
            for (int i = 1; i <= n; ++i) {
                mx[i][j] = std::max(mx[i][j - 1], mx[std::max(i - (1 << (j - 1)), 0)][j - 1]);
                mn[i][j] = std::min(mn[i][j - 1], mn[std::max(i - (1 << (j - 1)), 0)][j - 1]);
            }
        }
        dp[1] = 0;
        inc.push_back(1);
        dec.push_back(1);
        for (int i = 2; i <= n; ++i) {
            while (!inc.empty()) {
                int left = inc.back();
                int mn = find_min(left + 1, i - 1);
                if (h[i] < mn) dp[i] = std::min(dp[i], dp[left] + 1);
                if (h[i] <= h[left]) inc.pop_back();
                else break;
            }
            inc.push_back(i);
            while (!dec.empty()) {
                int left = dec.back();
                int mx = find_max(left + 1, i - 1);
                if (h[i] > mx) dp[i] = std::min(dp[i], dp[left] + 1);
                if (h[i] >= h[left]) dec.pop_back();
                else break; 
            }
            dec.push_back(i);
        }
        std::cout << dp[n] << '\n';
    }

    return 0;
}
// 23 : 02 -  23 ; 46