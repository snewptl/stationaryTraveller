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
std::vector<pii> vec[maxn];
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
        for (int i = 0; i <= n; ++i) {
            vec[i].clear();
        }
        for (int i = 1; i <= n; ++i) {
            int m, p;
            std::cin >> m >> p;
            vec[m].push_back({p, i});
        }
        int before = n;
        std::set<pii> s;
        ll ans = 0;
        int bought = 0;
        for (int i = n - 1; i >= 0; --i) {
            before -= vec[i].size();
            for (auto it : vec[i]) {
                s.insert(it);
            }
            while (before + bought < i) {
                bought += 1;
                ans += s.begin()->first;
                s.erase(s.begin());
            }
        }
        std::cout << ans << '\n';
    }

    return 0;
}
// 16 : 52 - 17 : 33