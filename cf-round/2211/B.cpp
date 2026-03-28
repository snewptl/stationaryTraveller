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
int x, y;
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
        std::cin >> x >> y;
        int res = std::abs(x - y);
        if (res == 0) {
            std::cout << 1 << '\n';
        } else {
            int count =  0;
            for (int i = 1; i <= res; ++i) {
                if (res % i == 0) count += 1;
            }
            std::cout << count << '\n';
        }
        for (int i = 1; i <= x; ++i) std::cout << 1  << ' ';
        for (int i = 1; i <= y; ++i) std::cout << -1  << ' ';
        std::cout << '\n';
    }

    return 0;
}
