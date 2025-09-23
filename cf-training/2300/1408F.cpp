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
int n, q;
std::vector<pii> opt;
void solve(int l, int r) {
    if (l == r) return;
    int mid = (l + r) / 2;
    solve(l, mid);
    solve(mid + 1, r);
    for (int i = l, j = mid + 1; i <= mid; ++i, ++j) {
        opt.push_back({i, j});
    }
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    opt.clear();
    if (n == 1) {
        std::cout << "0\n";
    } else {
        solve(1, 1 << std::__lg(n - 1));
        solve(n - (1 << std::__lg(n - 1)) + 1, n);
        std::cout << opt.size() << '\n';
        for (auto [x, y] : opt) {
            std::cout << x << ' ' << y << '\n';
        }
    }
    return 0;
}
// 16 : 15 -  16 : 48