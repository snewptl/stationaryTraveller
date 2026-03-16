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
ll a, b, c, m;
ll lcm(ll x, ll y) {
    return x * y / std::__gcd(x, y);
}
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
        std::cin >> a >> b >> c >> m;
        ll count[4] = {0, 0, 0, 0};
        count[3] = m / lcm(lcm(a, b), c);
        count[2] = m / lcm(a, b) + m / lcm(b, c) + m / lcm(c, a) - 3 * count[3];
        // count[1] = m / a + m / b + m / c - count[2] - count[3];
        // ll all = count[1] * 6 + count[2] * 6 + count[3] * 6;
        ll alice = m / a * 6 - (count[2] - m / lcm(b, c) + count[3]) * 3 - count[3] * 4;
        ll bob = m / b * 6 - (count[2] - m / lcm(a, c) + count[3]) * 3 - count[3] * 4;
        ll carol = m / c * 6 - (count[2] - m / lcm(a, b) + count[3]) * 3 - count[3] * 4;
        std::cout << alice << ' ' << bob << ' ' << carol << '\n';
        // std::cout << count[1] * 6 + count[2] * 6 + count[3] * 6 << '\n';
    }

    return 0;
}
