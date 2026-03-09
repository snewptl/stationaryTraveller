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
int n, m, l;
int val[maxn];
int vis[maxn];
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
        std::cin >> n >> m >> l;
        for (int i = 1; i <= m; ++i) {
            val[i] = 0;
        }
        for (int i = 1; i <= l; ++i) {
            vis[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            int cur; std::cin >> cur;
            vis[cur] = 1;
        }
        int remain = n;
        for (int i = 1; i <= l; ++i) {
            int min = 1e9;
            int end = std::min(remain + 1, m);
            for (int j = 1; j <= end; ++j) {
                min = std::min(min, val[j]);
            }
            for (int j = end; j >= 1; --j) {
                if (val[j] == min) {
                    val[j] += 1;
                    break;
                }
            }
            if (vis[i]) {
                val[end] = 0;
                if (remain + 1 > m) {
                    for (int i = m; i >= 2; --i) {
                        val[i] = val[i - 1];
                    }
                    val[1] = 0;
                } 
                remain -= 1;
            }
        }
        int max = 0;
        for (int i = 1; i <= m; ++i) {
            max = std::max(max, val[i]);
        }
        std::cout << max << '\n';
    }

    return 0;
}
