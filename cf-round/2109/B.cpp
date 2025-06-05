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
int n, m, a, b;
int solve(int x, int y) {
    int cnt = 0;
    while (x > 1) {
        x = (x + 1) / 2;
        cnt ++;
    }
    while (y > 1) {
        y = (y + 1) / 2;
        cnt += 1;
    }
    return cnt;
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
        std::cin >> n >> m >> a >> b;
        std::cout << std::min(solve(std::min(a, n - a + 1), m), solve(n, std::min(b, m - b + 1))) + 1 << '\n';
    }

    return 0;
}
