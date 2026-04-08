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
int p[maxn];
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
        }
        for (int i = 1; i <= k; ++i) {
            std::cin >> p[i];
        }

        int le = 1, ri = 1;
        for (int i = 2; i <= p[1]; ++i) {
            if (a[i] != a[i - 1]) le += 1;
        }
        for (int i = n - 1; i >= p[1]; --i) {
            if (a[i] != a[i + 1]) ri += 1;
        }
        if (a[1] == a[p[1]]) le -= 1;
        if (a[n] == a[p[1]]) ri -= 1;
        std::cout << std::max(le, ri) << '\n'; 
    }

    return 0;
}
