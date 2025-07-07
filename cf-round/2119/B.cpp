#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <bitset>
#include <memory.h>
#include <assert.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
const ll mod = 998244353;
int n;
pll p, q;
ll a[maxn];
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
        std::cin >> p.first >> p.second >> q.first >> q.second;
        ll mx = 0, sum = 0;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            mx = std::max(mx, a[i]);
            sum += a[i];
        }
        ll dis = (p.first - q.first) * (p.first - q.first) + (p.second - q.second) * (p.second - q.second);
        if (sum * sum >= dis && std::max(2 * mx - sum, 0ll) * std::max(2 * mx - sum, 0ll) <= dis) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }

    return 0;
}
