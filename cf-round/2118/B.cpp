#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <assert.h>
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
int n;
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
        std::vector<std::pair<int, pii>> vec;
        for (int i = 1; i < n; ++i) {
            vec.push_back({i, {1, n - i + 1}});
        }
        for (int i = n; i >= 3; --i) {
            vec.push_back({i, {n - i + 2, n}});
        }
        std::cout << vec.size() << '\n';
        for (auto it : vec) {
            std::cout << it.first << " " << it.second.first << " " << it.second.second << '\n';
        }
    }

    return 0;
}
// 4 3 2 1 1 2 3

// 4 3 2 1
// 3 2 1 4
// 2 1 3 4
// 1 2 3 4

// 4 3 2 1
// 3 2 1 4
// 2 1 3 4
// 1 4 3 2

// 4 3 2 1
// 3 2 1 4
// 2 1 4 3
// 1 4 3 2

// 5 4 3 2 1
// 4 3 2 1 5
// 3 2 1 4 5
// 2 1 3 4 5
// 1 2 3 4 5

// 5 4 3 2 1
// 4 3 2 1 5
// 3 2 1 4 5
// 2 1 3 4 5
// 1 5 4 3 2

// 3 2 1
// 2 1 3
// 1 2 3