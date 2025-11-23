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
int n, x, y;
std::string s;
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> x >> y;
        std::cin >> s;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '8') count += 1;
        }
        x = std::abs(x);
        y = std::abs(y);
        if (x > y) std::swap(x, y);
        int temp = std::min(x, count);
        int res = x + y - temp;
        if (res <= n) std::cout << "YES\n";
        else std::cout << "NO\n";
    }

    return 0;
}
