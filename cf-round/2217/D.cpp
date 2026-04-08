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
int n, k, x;
int a[maxn];
int p[maxn];
int marked[maxn];
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
        std::cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            marked[i] = 0;
        }
        for (int i = 1; i <= k; ++i) {
            std::cin >> p[i];
            marked[p[i]] = 1;
        }
        x = a[p[1]];
        int count = 0;
        int tot = 0;
        int max = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] != x) {
                if (i == 1) count += 1;
                else if (a[i - 1] == x) count += 1;
            } else {
                if (marked[i]) {
                    if (count) {
                        tot += count;
                        max = std::max(max, count);
                        count = 0;
                    }
                }
            }
        }
        if (count) {
            tot += count;
            max = std::max(max, count);
            count = 0;
        }
        int ans = tot;
        if (max * 2 > tot) {
            ans += max * 2 - tot;
        }
        std::cout <<  ans  << '\n';
    }

    return 0;
}

