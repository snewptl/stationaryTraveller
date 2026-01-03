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
int a[maxn], b[maxn], c[maxn];
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
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            std::cin >> b[i];
        }
        for (int i = 1; i <= n; ++i) {
            std::cin >> c[i];
        }
        int up = 0, dn = 0;
        for (int i = 0; i < n; ++i) {
            int flag = 1;
            for (int j = 1; j <= n; ++j) {
                int pos_a = j + i, pos_b = j;
                if (pos_a > n) pos_a -= n;
                if (a[pos_a] >= b[pos_b]) flag = 0;
            }
            up += flag;
        }
        for (int i = 0; i < n; ++i) {
            int flag = 1;
            for (int j = 1; j <= n; ++j) {
                int pos_c = j + i, pos_b = j;
                if (pos_c > n) pos_c -= n;
                if (c[pos_c] <= b[pos_b]) flag = 0;
            }
            dn += flag;
        }
        std::cout << 1ll * up * dn * n << '\n';
    }

    return 0;
}
