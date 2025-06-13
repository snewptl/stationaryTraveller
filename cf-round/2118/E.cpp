#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <assert.h>
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
        std::cin >> n >> m;
        std::vector<pii> ans;
        pii row = {1, n}, col = {1, m};
        while (std::min(n, m) > 0) {
            std::vector<pii> vec;
            if (n > m) {
                int mid = (col.first + col.second) / 2;
                vec.push_back({row.first, mid});
                vec.push_back({row.second, mid});
                for (int i = 1; i <= m / 2; ++i) {
                    vec.push_back({row.first, mid - i});
                    vec.push_back({row.second, mid - i});
                    vec.push_back({row.first, mid + i});
                    vec.push_back({row.second, mid + i});
                }
                n -= 2;
                row.first += 1;
                row.second -= 1;
            } else {
                int mid = (row.first + row.second) / 2;
                if (m == 1) {
                    vec.push_back({row.first, col.first});
                } else {
                    vec.push_back({mid, col.first});
                    vec.push_back({mid, col.second});
                }
                for (int i = 1; i <= n / 2; ++i) {
                    vec.push_back({mid - i, col.first});
                    vec.push_back({mid - i, col.second});
                    vec.push_back({mid + i, col.first});
                    vec.push_back({mid + i, col.second});
                }
                m -= 2;
                col.first += 1;
                col.second -= 1;
            }
            std::reverse(all(vec));
            for (auto it : vec) ans.push_back(it);
        }
        std::reverse(all(ans));
        for (auto it : ans) std::cout << it.first << " " << it.second << '\n';
    }

    return 0;
}
