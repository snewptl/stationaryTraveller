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
const int maxn = 6e5 + 5;
const ll mod = 998244353;
int n;
ll b[maxn];
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
        for (int i = 1; i <= n; ++i) std::cin >> b[i];
        ll lcm = 1;
        for (int i = 1; i < n; ++i) {
            if (b[i + 1] % b[i] != 0) {
                ll d = std::__gcd(b[i], b[i + 1]);
                ll x = b[i] / d;
                lcm = x / std::__gcd(x, lcm) * lcm;
            }
        }
        std::cout << lcm << '\n';

    }

    return 0;
}
