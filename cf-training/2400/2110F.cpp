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
const int maxn = 1e6 + 5;
const ll mod = 998244353;
int n;
int a[maxn];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; std::cin >> T;
    while (T--) {
        std::cin >> n;
        std::set<int> s;
        int ans = 0;
        int max = 0;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            int l = a[i], r = a[i] * 2 - 1;
            auto it = s.upper_bound(r);
            if (it != s.end()) {
                int cur = *it;
                ans = std::max(ans, cur % a[i] + a[i] % cur);
            }
            if (it != s.begin()) {
                --it;
                int cur = *it;
                ans = std::max(ans, cur % a[i] + a[i] % cur);
            }
            if (max < a[i]) {
                it = s.lower_bound(a[i]);
                if (it != s.begin()) {
                    --it;
                    int cur = *it;
                    if (cur > a[i]  / 2) {
                        ans = std::max(a[i], ans);
                    } else {
                        for (int j = 1; j < i; ++j) {
                            ans = std::max(a[j] % a[i] + a[i] % a[j], ans);
                        }
                    }
                }
                max = a[i];
            }
            ans = std::max(ans, max % a[i] + a[i] % max);
            s.insert(a[i]);
            std::cout << ans << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}
