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
const int maxn = 2e5 + 5;
const ll mod = 998244353;
int n, a[maxn];
int solve() {
    int ans = 0, flag = 0;
    for (int i = 2; i <= n; ++i) {
        if (std::abs(a[i] - a[i - 1]) <= 1) return 0;
        if (a[i] > a[i - 1]) {
            if (flag == -1) ans = 1;
            else flag = 1;
        } else {
            if (flag == 1) ans = 1;
            else flag = -1;
        }
    }
    if (!ans) return -1;
    else return ans;
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
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        std::cout << solve() << '\n';
    }

    return 0;
}
