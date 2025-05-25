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
int n;
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    // std::cin >> T;
    while (T--) {
        std::cin >> n;
        std::vector<int> vec{-4, -3, 3, -1, 1, 4};
        if (n % 2) {
            if (n <= 5) {
                std::cout <<"NO\n";
            } else {
                std::cout <<"YES\n";
                std::cout << "3 2 -1 1 2 ";
                n -= 5;
                for (int i = 1; i <= n/6; ++i) {
                    for (auto it : vec)
                        std::cout << it << ' ';
                }
                for (int i = 1; i <= n % 6; ++i)
                    std::cout << vec[i - 1] << ' ';
                std::cout << '\n';
            }
        } else {
            std::cout <<"YES\n";
            for (int i = 1; i <= n/6; ++i) {
                for (auto it : vec)
                    std::cout << it << ' ';
            }
            for (int i = 1; i <= n % 6; ++i)
                std::cout << vec[i - 1] << ' ';
            std::cout << '\n';
        }
    }

    return 0;
}
