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
int n, k;
int a[maxn];
int count[maxn];
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
        for (int i = 1; i <= n + 1; ++i) {
            count[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            count[a[i]] += 1;
        }
        for (int i = n - 1; i >= 1; --i) {
            count[i] += count[i + 1];
        }
        std::sort(a + 1, a + n + 1);
        int ans = 1;
        for (int i= n; i >= 2; --i) {
            int num = 0;
            if (i * 4 <= n) num += count[i * 4];
            for (int j = i; j <= std::min(n, i * 3); j += i) {
                num += count[j] - count[j + 1];
            }
            if (num >= n - k) {
                ans = i;
                break;
            }
        }
        std::cout << ans << '\n';
    }

    return 0;
}
