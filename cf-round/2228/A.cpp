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
int cnt[3];
int n;
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
        for (int i = 0; i < 3; ++i) {
            cnt[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            int x;
            std::cin >> x;
            cnt[x] += 1;
        }
        int ans = cnt[0];
        int temp = std::min(cnt[1], cnt[2]);
        ans += temp;
        ans += (cnt[1] - temp) / 3 + (cnt[2] - temp) / 3;
        std::cout << ans << '\n';
    }

    return 0;
}
