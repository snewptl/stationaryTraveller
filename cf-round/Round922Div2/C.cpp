#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#define all(x) x.begin(), x.end()
typedef int64_t ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const ll mod = 998244353;
const int maxn = 2e5 + 5;
const double eps = 1e-10;
ll a, b, x;
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> a >> b >> x;
        if (a < b) std::swap(a, b);
        int flag = 1;
        for (int i = 63; i >= 0; --i) {
            ll del = 1ll << i;
            if ((a & del) && !(b & del)) {
                if (flag) {
                    flag = 0;
                    continue;
                }
                if (x < del) continue;
                x -= del;
                a ^= del;
                b ^= del;
            }
        }
        std::cout << a - b << '\n';
    }

    return 0;
}
