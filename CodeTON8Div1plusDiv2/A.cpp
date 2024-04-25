#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
int n, k;
int a[maxn];
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> k;
        if (k == 1) {
            std::cout << "1 ";
            for (int i = 1; i < n; ++i) {
                std::cout << "2 ";
            }
            std::cout << '\n';
        } else {
            if (n == k) {
                for (int i = 1; i <= n; ++i) {
                    std::cout << "1 ";
                }
                std::cout << '\n';
            } else {
                std::cout << "-1\n";
            }
        }
    }

    return 0;
}
