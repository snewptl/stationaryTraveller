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
ll n, k;
std::map<pli, ll> dep, val;
std::map<ll, std::vector<pii>> vec;
ll ans;
ll lowbit(ll x) {
    return x & (-x);
}
bool my_sort(pll x, pll y) {
    if (x.first != y.first) return x.first > y.first;
    else return x.second < y.second;
}
void cal_vec(ll x) {
    int last = -1;
    for (int i = 0; i < 35; ++i) {
        if ((1ll << i) & x) {
            if (last == -1) last = i;
        } else {
            if (last != -1) vec[x].push_back({i - last, last});
            last = -1;
        }
    }
    if (last != -1) vec[x].push_back({35 - last, last});
    std::sort(all(vec[x]), my_sort);
}
void bfs() {
    dep[{n, 0}] = 0;
    val[{n, 0}] = 0;
    std::queue<pli> q;
    q.push({n, 0});
    cal_vec(n);
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        if (dep[p] == k) {
            ans = std::max(ans, val[p]);
            continue;
        }
        int count = 0;
        for (ll i = 1 << p.second; i <= p.first ; i *= 2) {
            if (i & p.first) count += 1;
        }
        if (count == 1) {
            ans = std::max(ans, val[p] + k - dep[p]);
            continue;
        } 

        for (auto [len, start] : vec[p.first]) {
            if (start < p.second) continue;
            pli new_p = {p.first + (1ll << start), start};
            // if (dep[new_p] && dep[new_p] <= dep[p]) continue;

            if (!dep[new_p]) {
                dep[new_p] = dep[p] + 1;
                cal_vec(new_p.first);
                q.push(new_p);
            }
            if (val[new_p] < len + val[p]) {
                val[new_p] = len + val[p];
            }
        }
        
    }
}
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
        std::cin >> n >> k;
        dep.clear();
        vec.clear();
        val.clear();
        ans = 0;
        bfs();
        std::cout << ans << '\n';
    }

    return 0;
}