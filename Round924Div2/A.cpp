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
const int maxn = 2e5 + 5;
int n, m;
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> m;
        if (n > m)  std::swap(n, m);
        if (n % 2 == 0) std::cout << "Yes\n";
        else if (m % 2 == 0) {
            if (m == n * 2) std::cout << "No\n";
            else std::cout << "Yes\n";
        }
        else std::cout << "No\n";
    }

    return 0;
}
