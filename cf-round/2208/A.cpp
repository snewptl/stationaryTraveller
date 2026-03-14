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
int n;
int a[105][105];
int count[10005];
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
        int max = 0, pos = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                std::cin >> a[i][j];
                count[a[i][j]] += 1;
                if (count[a[i][j]] > max) {
                    max = count[a[i][j]];
                    pos = a[i][j];
                }
            }
        }
        int end = n * n - n;
        if (n == 1) end = 0;
        if (max > end) std::cout << "NO\n";
        else std::cout << "YES\n";

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                count[a[i][j]] = 0;
            }
        }
    }

    return 0;
}
