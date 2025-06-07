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
int n, a[maxn];
std::set<pii> s[2], t;
ll sum[maxn];
int vis[maxn];
int available[maxn];
int solve() {
    if (s[0].empty()) return 0;
    for (int i = 1; i <= n; ++i) {
        auto it = s[0].lower_bound({i + 1, 0});
        if (it == s[0].begin()) continue;
    }
}
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
            std::cin >> a[i];
            sum[i] = a[i] + sum[i - 1];
        }
        s[0].clear();
        s[1].clear();
        t.clear();
        s[0].insert({a[1], a[1]});
        vis[a[1]] = 1;
        for (int i = 2; i <= n; ++i) {
            if (vis[a[i]]) {
                if(!s[0].empty()) {
                    auto it = s[0].end();
                    --it;
                    if (it->second < i - 1) {
                        continue;
                    }
                    if (it->first + a[i] <= it->second + 1) {
                        pii cur = {std::max(it->first, i - 1), std::min(it->second + a[i], n)};
                        s[0].erase(it);
                        s[0].insert(cur);
                    } else {
                        if (it->first + a[i] <= n) {
                            s[0].insert(std::max(it->first + a[i], i - 1), std::min(it->second + a[i], n));
                        }
                    }
                }
                continue;
            } 
            vis[a[i]] = 1;
            for (auto p : s[0]) {
                if (p.second >= i - 1) {
                    s[1].insert(p);
                    if (p.first + a[i] <= n) {
                        s[1].insert({p.first + a[i], std::min(n, p.second + a[i])});
                    }
                } else {
                    t.insert(p);
                }
            }
            s[0].clear();
            pii cur = {0, 0};
            while (!s[1].empty()) {
                auto cur = *s[1].begin();
                s[1].erase(s[1].begin());
                if (s[1].empty()) {
                    s[0].insert(cur);
                    break;
                }
                auto it = s[1].begin();
                while (it->first <= cur.second + 1) {
                    cur.second = std::max(cur.second, it->second);
                    s[1].erase(it);
                    if (s[1].empty()) break;
                    it = s[1].begin();
                } 
                s[0].insert(cur);
            }
        }
        for (auto it : s[0]) t.insert(it);
        
        std::cout << solve() << '\n';
    }

    return 0;
}
