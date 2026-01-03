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
int n;
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
        std::cin >> n >> s;
        int y25 = 0, y26 = 0;
        for (int i = 0; i <= n - 3; ++i) {
            std::string t;
            for (int j = i; j <= i + 3; ++j) {
                t += s[j];
            }
            if (t == "2025") y25 = 1;
            if (t == "2026") y26 = 1;
        }
        if (y25 && !y26) std::cout << "1\n";
        else std::cout << "0\n";
    }

    return 0;
}
