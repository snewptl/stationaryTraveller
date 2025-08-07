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
int n, x;
std::string s;
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
        std::cin >> n >> x >> s;
        int left = 1, right = 1;
        for (int i = 1; i < x; ++i) {
            if (s[i - 1] == '#') left = i + 1;
        }
        for (int i = n; i > x; --i) {
            if (s[i - 1] == '#') right = n - i + 1 + 1;
        }        
        std::cout << std::max(std::min(left, n - x + 1), std::min(right, x)) << '\n';
    }

    return 0;
}
