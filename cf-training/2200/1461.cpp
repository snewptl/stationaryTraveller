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
const int maxn = 1e6 + 5;
const ll mod = 998244353;
ll k, l, r, t, x, y;
ll dis[maxn];
ll last[maxn];
ll mx;
bool is_inf, flag;
void solve(ll k, ll dep) {
    if (last[k % x] != -1) {
        if (k >= last[k % x]) {
            is_inf = 1;
            return;
        } else {
            ll add = k / (x - y);
            mx = std::max(dep + add, mx);
            return;
        }
    }
    dis[k % x] = dep;
    last[k % x] = k;
    mx = std::max(mx, dep);
     
    if (!add) return;
    k -= x;
    solve(k, dep + 1); 
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> k >> l >> r >> t >> x >> y;
    for (int i = 0; i < x; ++i) last[i] = -1;

    k -= l;
    r -= l;
    solve(k, 0);
    if (mx >= t || is_inf) std::cout << "YES\n";
    else std::cout << "NO\n";

    return 0;
}
// 13 : 21 - 
