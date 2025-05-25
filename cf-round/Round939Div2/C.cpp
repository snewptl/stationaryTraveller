#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
int n, sum[maxn];
void print(int c, int index) {
    std::cout << c << ' ' << index << ' ';
    for (int i = 1; i <= n; ++i) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}
int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    sum[0] = 0;
    for (int i = 1; i <= 500; ++i) {
        sum[i] = i * (2 * i - 1) + sum[i - 1];
    }
    while (T--) {
        std::cin >> n;
        std::cout << sum[n] << ' ' << 2 * n - 1 << '\n';
        print(1, n);
        for (int i = n - 1; i >= 1; i--) {
            print(1, i);
            print(2, i);
        }
    }

    return 0;
}
