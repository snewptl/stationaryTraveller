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
const int maxn = 4e5 + 5;
const ll mod = 998244353;
int n, l, r;
int a[maxn];
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
        std::cin >> n >> l >> r;
        if (l == r) l = r = -1;
        for (int i = 1; i <= n; ++i) {
            if (i == r) {
                a[i] = (l - 1) ^ (i - 1);
            } else if (i == r + 1) {
                a[i] = i ^ (l - 1);
            } else {
                a[i] = i ^ (i - 1);
            }
        }
        for (int i = 1; i <= n; ++i) {
            std::cout << a[i] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
