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
pll top_right, bottom_right;
pll node[105];
pll ans;
int n;
ll ask(std::string dir, ll dis) {
    std::cout << "? " << dir << " " << dis << std::endl;
    ll res = 0;
    std::cin >> res;
    return res;
}
void output() {
    std::cout << "! " << ans.first << ' ' << ans.second << std::endl;
}
int main() {
    #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        ll top = -1e9, right = -1e9, bottom = 1e9;
        for (int i = 1; i <= n; ++i) {
            std::cin >> node[i].first >> node[i].second;
            top = std::max(top, node[i].second);
            right = std::max(right, node[i].first);
            bottom = std::min(bottom, node[i].second);
        }
        top_right = {right, top};
        bottom_right = {right, bottom};
        ask("R", 1e9);
        ask("R", 1e9);
        ask("U", 1e9);
        ll dis1 = ask("U", 1e9);
        ask("D", 1e9);
        ask("D", 1e9);
        ask("D", 1e9);
        ll dis2 = ask("D", 1e9);
        ll reduce1 = 1e18, reduce2 = 1e18;
        for (int i = 1; i <= n; ++i) {
            reduce1 = std::min(reduce1, right - node[i].first + top - node[i].second);
            reduce2 = std::min(reduce2, right - node[i].first + node[i].second - bottom);
        }
        dis1 -= reduce1;
        dis2 -= reduce2;
        ans.first = ((dis1 + dis2) + (right * 2 + top - bottom) - 4 * 2e9) / 2;
        ans.second = dis1 - ans.first - 4e9 + right + top;
        output();
    }

    return 0;
}
