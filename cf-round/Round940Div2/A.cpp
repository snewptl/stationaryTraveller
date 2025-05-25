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
int vis[105], n;
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
        for (int i = 1; i <= n; ++i) {
            int x;
            std::cin >> x;
            vis[x]++;
        }
        int tot = 0;
        for (int i = 1; i <= 100; ++i) {
            tot += vis[i] / 3;
        }
        std::cout << tot << '\n';

        for (int i = 1; i <= 100; ++i) {
            vis[i] = 0;
        }
    }

    return 0;
}
