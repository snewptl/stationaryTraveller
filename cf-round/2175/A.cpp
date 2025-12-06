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
int n, a[maxn];
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
        std::sort(a + 1, a + n + 1);
        int new_n = std::unique(a + 1, a + n + 1) - (a + 1);
        int flag = 0;
        for (int i = 1; i <= new_n; ++i) {
            if (a[i] >= new_n) {
                flag = a[i];
                break;
            }
        }
        ll max = 1e18;
        if (flag) std::cout << flag << '\n';
        else std::cout << max + new_n - 1 << '\n'; 
    }

    return 0;
}
