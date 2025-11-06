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
int n, m;
int a[maxn], b[maxn], c[maxn];
std::vector<pii> vec[2];
std::set<pii> s;
int ans;
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
        std::cin >> n >> m;
        vec[0].clear();
        vec[1].clear();
        ans = 0;
        s.clear();
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            s.insert({a[i], i});
        }
        for (int i = 1; i <= m; ++i) {
            std::cin >> b[i];
        }
        for (int i = 1; i <= m; ++i) {
            std::cin >> c[i];
            vec[c[i] > 0].push_back({b[i], c[i]});
        }
        std::sort(all(vec[0]));
        std::sort(all(vec[1]));
        for (auto [in, out] : vec[1]) {
            auto it = s.lower_bound({in, 0});
            if (it != s.end()) {
                auto [new_in, id] = *it;
                s.erase(it);
                s.insert({std::max(new_in, out), id});
                ans += 1;
            }
        }
        for (auto [in, out] : vec[0]) {
            auto it = s.lower_bound({in, 0});
            if (it != s.end()) {
                auto [new_in, id] = *it;
                s.erase(it);
                ans += 1;
            }
        }
        std::cout << ans << '\n';
    }

    return 0;
}
