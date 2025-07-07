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
ll n, l, r, k;
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
        std::cin >> n >> l >> r >> k;
        if (n % 2) {
            std::cout << l << '\n';
        } else if (n != 2) {
            ll cur = 1;
            while (cur <= l) cur *= 2;
            if (r >= cur) {
                if (k <= n - 2) std::cout << l << '\n';
                else std::cout << cur << '\n';
            } else {
                std::cout << "-1\n";
            }
        } else {
            std::cout << "-1\n";
        }
    }

    return 0;
}
