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
int n, a[maxn], vis[maxn];
int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            vis[a[i]]++;
            if (vis[a[i]] == 2) {
                ans++;
            }
        }
        for (int i = 1; i <= n; ++i) {
            vis[a[i]] = 0;
        }
        std::cout << ans << '\n';
    }

    return 0;
}
