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
int b[105];

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
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            std::cin >> b[i];
        }
        std::sort(b + 1, b + n + 1);
        int flag = 1;
        for (int i = 1; i <= n - 2; ++i) {
            if (b[i] != b[i + 2] % b[i + 1]) {
                flag = 0;
            }
        }
        if (flag) std::cout << b[n] << ' ' << b[n - 1] << '\n';
        else std::cout << "-1\n";
    }

    return 0;
}
