#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <assert.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 1e6 + 5;
int n;
ll count[maxn], vis[maxn], used[maxn];
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
            count[x]++;
        }
        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (vis[i] == 1) continue;
            if (used[i] == 0 && !count[i]) continue;
            ll cur = 0;
            ll pre = vis[i];
            for (int j = i; j <= n; j += i) {
                used[j] = 1;
                vis[j] -= pre - 1;
                cur += count[j];
            }
            ans += (1 - pre) * cur * (cur - 1) / 2;
        }
        std::cout << 1ll * n * (n - 1) / 2 - ans << '\n';
        for (int i = 1; i <= n; ++i) count[i] = vis[i] = used[i] = 0;
    }

    return 0;
}
