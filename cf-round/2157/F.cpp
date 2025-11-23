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
std::vector<pii> vec;
void solve(int fac, int n) {
    if (fac == n) return; 
    for (int j = 62; j >= 1; --j) {
        for (int i = n - fac * j; i >= fac; i -= fac * 63) {
            vec.push_back({i, fac});
        }
    }
    solve(fac * 63, n);
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    n = 63 * 63 * 63;
    solve(1, n);
    std::cout << vec.size() << '\n';
    for (auto [f, s] : vec) {
        std::cout << f << ' ' << s << '\n';
    }
 
    return 0;
}
