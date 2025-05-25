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
const ll mod = 999999893;
const int maxn = 2e5 + 5;
const double eps = 1e-10;

int main() {
    // freopen("intput.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    for (int i = 2; i * i < mod; ++i) {
        if (mod % i == 0) {
            std::cout << i << '\n';
            return 0;
        }
    }
    std::cout << "isPrime!\n";
    return 0;
}
