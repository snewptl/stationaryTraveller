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
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    if (n <= 2) {
        std::cout << "No\n";
    } else {
        std::cout << "Yes\n";
        if (n % 2 != 0) {
            std::cout << n - 1 << ' ';
            for (int i = 1; i <= n / 2; ++i) {
                std::cout << i << ' ' << n - i + 1 << ' ';
            }
            std::cout << '\n';
            std::cout << "1 " << (n + 1) / 2 << '\n';
        } else {
            std::cout << (n / 2 + 1) / 2 * 2 << ' ';
            for (int i = 1; i <= n / 2; i += 2) {
                std::cout << i << ' ' << n - i + 1 << ' ';
            }
            std::cout << '\n';
            std::cout << (n / 2) / 2 * 2 << ' ';
            for (int i = 2; i <= n / 2; i += 2) {
                std::cout << i << ' ' << n - i + 1 << ' ';
            }
            std::cout << '\n';
        }
    }

    return 0;
}
