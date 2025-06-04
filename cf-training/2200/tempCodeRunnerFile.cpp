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
int n, a[maxn];
std::vector<int> vec[maxn];
int level[maxn];
std::set<pii> s;
int max;
int ans[maxn];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    // std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            vec[a[i]].push_back(i);
            max = std::max(max, a[i]);
        }
        s.insert({1, n});
        for (int i = 1; i <= max; ++i) {
            for (auto idx : vec[i - 1]) {
                if (s.empty()) break;
                pii cur = {idx, n + 1};
                auto it = s.upper_bound(cur);
                if (it == s.begin()) continue;
                --it;
                auto [l, r] = *it;
                if (r >= idx && l <= idx) {
                    s.erase(it);
                    if (l < idx) s.insert({l, idx - 1});
                    if (r > idx) s.insert({idx + 1, r});
                }
            }
            level[i] = s.size();
        }
        for (int i = 1; i <= max; ++i) {
            for (int j = 1; j <= max; j += i) {
                ans[i] += level[j];
            }
            std::cout << ans[i] << ' ';
        }
        std::cout << '\n';
        
    }

    return 0;
}
