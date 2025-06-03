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
int n, m;
int f[15];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i <= 11; ++i) f[i] = f[i - 1] + f[i - 2];
    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> m;
        for (int i = 1; i <= m; ++i) {
            int w, l, h;
            std::cin >> w >> l >> h;
            int max = std::max(std::max(w, l), h);
            int min = std::min(std::min(w, l), h);
            if (max >= f[n + 1] && min >= f[n]) std::cout << '1';
            else std::cout << '0';
        }
        std::cout << '\n';
    }

    return 0;
}
