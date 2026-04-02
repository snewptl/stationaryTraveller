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
int a[maxn];
int c[maxn];
ll sum[maxn];
int vis[maxn];
int p[maxn];
int fa[maxn];
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
        std::set<int> s;
        std::set<pii> hp;
        for (int i = 1; i <= n; ++i) {
            vis[i] = 0;
            s.insert(i);
            fa[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        std::set<pii, std::greater<pii>> remain;
        for (int i = 1; i <= n; ++i) {
            std::cin >> c[i];
            hp.insert({c[i], i});
            remain.insert({a[i], i});
        }
        for (int i = 1; i <= n; ++i) {
            std::cin >> p[i];
        }
        ll ans = 0;
        
        while (!hp.empty()) {
            auto [cost, id] = *hp.begin();
            hp.erase(hp.begin());
            if (!s.count(id)) continue;
            std::vector<int> vec;
            vec.push_back(id);
            auto pre = s.lower_bound(id);
            while (pre != s.begin()) {
                --pre;
                if (a[*pre] > a[id]) break;
                vec.push_back(*pre);
            }
            int last = id;
            while (true) {
                auto nxt = s.upper_bound(last);
                if (nxt == s.end()) break;
                if (a[*nxt] > a[id]) break;
                last = *nxt;
                vec.push_back(last);
            }
            for (auto cur : vec) {
                fa[cur] = id;
                s.erase(cur);
            }
        }
        for (int i = 1; i <= n; ++i) {
            ans += c[fa[i]];
        }
        for (int i = 1; i <= n; ++i) {
            s.insert(i);
        }
        std::cout << ans - c[fa[remain.begin()->second]] << ' ';
        for (int i = 1; i <= n; ++i) {
            int id = p[i];
            if (!s.count(id)) {
                std::cout << ans - c[fa[remain.begin()->second]] << ' ';
                continue;
            }
            std::vector<int> vec;
            vec.push_back(id);
            auto pre = s.lower_bound(id);
            while (pre != s.begin()) {
                --pre;
                if (a[*pre] > a[id]) break;
                vec.push_back(*pre);
            }
            int last = id;
            while (true) {
                auto nxt = s.upper_bound(last);
                if (nxt == s.end()) break;
                if (a[*nxt] > a[id]) break;
                last = *nxt;
                vec.push_back(last);
            }
            for (auto cur : vec) {
                ans -= c[fa[cur]];
                s.erase(cur);
            }
            c[id] = 0;
            for (auto cur : vec) {
                fa[cur] = id;
            }
            std::cout << ans - c[fa[remain.begin()->second]] << ' ';
        }
        std::cout << '\n';
        


    }

    return 0;
}
// 20 : 41 - 