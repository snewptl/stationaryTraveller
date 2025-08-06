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
std::set<std::pair<int, pll>> pairs;
std::set<std::pair<pll, int>> lens;
int res[maxn];
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
        pairs.clear();
        lens.clear();
        for (int i = 1; i <= n; ++i) {
            int a, b;
            std::cin >> a >> b;
            pairs.insert({i, {a, b}});
            lens.insert({{a, b}, i});
        }
        ll cur = 0;
        while (!lens.empty()) {
            auto [p, i] = *lens.begin();
            auto [a, b] = p;
            cur = a;
            lens.erase(lens.begin());
            pairs.erase({i, p});
            auto nxt_ptr = pairs.lower_bound({i, p});
            if (nxt_ptr != pairs.begin()) {
                auto pre_ptr = nxt_ptr;
                --pre_ptr;
                auto nxt = *nxt_ptr;
                auto pre = *pre_ptr;
                if (pre.second.second == nxt.second.second) {
                    pairs.erase(nxt);
                    pairs.erase(pre);
                    std::pair<int, pll> new_p = {nxt.first, {pre.second.first + nxt.second.first - cur, pre.second.second}};
                    pairs.insert(new_p);
                    lens.erase({nxt.second, nxt.first});
                    lens.erase({pre.second, pre.first});
                    lens.insert({new_p.second, new_p.first});
                }
            }
        }
        std::cout << cur << '\n';
    }

    return 0;
}

// 15 : 25