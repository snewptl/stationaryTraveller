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
        std::cin >> s;
        int ans[2] = {0, 0};
        for (int i = 1; i < s.size() - 1; ++i) {
            if (s[i - 1] != s[i]) {
                if (s[i + 1] != s[i]) {
                    ans[1] = 1;
                } else {
                }
            } else {
                if (s[i + 1] != s[i]) {
                } else {
                    ans[0] = 1;
                }
            }
        }
        std::cout << ans[0] + ans[1] + 1 << '\n';
    }

    return 0;
}
