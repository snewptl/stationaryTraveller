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
int n, l, a[maxn], count[35];
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
        std::cin >> n >> l;
        for (int i = 0; i < 30; ++i) {
            count[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            for (int j = 0; j < 30; ++j) {
                if (a[i] & (1 << j)) count[j] += 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < 30; ++i) {
            if (count[i] >= (n + 1) / 2) {
                ans |= 1 << i;
            }
        }
        std::cout << ans << '\n';
        
    }

    return 0;
}
