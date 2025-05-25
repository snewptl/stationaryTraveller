#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 1e2 + 5;
int n, a[maxn], k, q;
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> k >> q;
        for (int i = 1; i <= k; ++i) {
            std::cin >> a[i];
        }
        for (int i = 1; i <= q; ++i) {
            int n;
            std::cin >> n;
            std::cout << std::min(a[1] - 1, n) << ' ';
        }
        std::cout << "\n";

    }

    return 0;
}
