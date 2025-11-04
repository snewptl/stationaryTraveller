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
int n, q;
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
        std::cin >> n >> q >> s;
        int flag = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'B') flag = 1;
        }
        for (int i = 1; i <= q; ++i) {
            int x;
            std::cin >> x;
            if (!flag) {
                std::cout << x << '\n';
            } else {
                int res = 0;
                for (int j = 0; x > 0; j = (j + 1) % n) {
                    res += 1;
                    if (s[j] == 'A') {
                        x -= 1;
                    } else {
                        x /= 2;
                    }
                }
                std::cout << res << '\n';
            }
        }
    }

    return 0;
}
