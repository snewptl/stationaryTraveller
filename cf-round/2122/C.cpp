#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <bitset>
#include <memory.h>
#include <assert.h>
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
int vis_x[maxn], vis_y[maxn];
pii pos[maxn], xr[maxn], yr[maxn];
ll ans;
std::set<int> s[4];
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
        ans = 0;
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            int x, y;
            std::cin >> x >> y;
            pos[i] = {x, y};
            xr[i] = {x, i};
            yr[i] = {y, i};
        } 
        for (int i = 0; i < 4; ++i) s[i].clear();
        std::sort(xr + 1, xr + n + 1);
        std::sort(yr + 1, yr + n + 1);
        for (int i = 1; i <= n / 2; ++i) {
            vis_x[xr[i].second] = 0;
            vis_y[yr[i].second] = 0;
        }
        for (int i = n / 2 + 1; i <= n; ++i) {
            vis_x[xr[i].second] = 1;
            vis_y[yr[i].second] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            s[vis_x[i] + vis_y[i] * 2].insert(i);
        }
        // assert(s[1].size() != s[2])
        std::vector<pii> ans;
        for (int i = 0; i < 2; ++i) {
            for (auto it : s[i]) {
                auto that = s[3 - i].begin();
                ans.push_back({it, *that});
                s[3 - i].erase(that);
            }
        }
        for (auto it : ans) {
            std::cout << it.first << ' ' << it.second << '\n';
        }
        
    }

    return 0;
}
