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
std::string s;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    // std::cin >> T;
    while (T--) {
        std::cin >> s;
        int n = s.size();
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            int cur = i, times = 1;
            while (cur % 2 == 0) cur /= 2, times *= 2;
            int j = 1, temp = cur;
            while (temp > 1) j *= 2, temp /= 2;
            if (j != cur) j *= 2;
            if (n % times == 0 && (n / times - 1) % j + 1 >= cur) {
                res ^= s[i - 1] - '0';
                std::cout << "$$$" << i << " " << j << '\n';
            } 
        }
        std::cout << res << '\n';
    }

    return 0;
}
