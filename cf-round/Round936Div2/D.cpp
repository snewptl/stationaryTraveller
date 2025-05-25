#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
int n, x;
int a[maxn];
int check(int x, int mask) {
    int xorSum = 0, count = 0;
    for (int i = 1; i <= n; ++i) {
        xorSum ^= a[i] & mask;
        if ((xorSum | x) == x) count++;
    }
    if ((xorSum | x) == x) return count;
    else return -1;
}
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> x;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        int mask = 0;
        int ans = -1;
        for (int i = 30; i >= 0; --i) {
            mask |= 1 << i;
            if ((1 << i) & x) {
                ans = std::max(ans, check((x & mask) ^ (1 << i), mask));
            }
        }
        ans = std::max(ans, check(x & mask, mask));
        std::cout << ans << '\n';
    }

    return 0;
}
