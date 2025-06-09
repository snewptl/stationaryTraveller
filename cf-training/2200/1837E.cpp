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
int k;
int a[maxn];
int n;
ll fac[maxn];
ll ans;
void solve() {
    ans = 1;
    std::vector<int> last, cur;
    for (int i = 1; i <= n; ++i) last.push_back(a[i]);
    int sz = last.size();
    while (last.size() > 1) {
        int count = sz / 2;
        for (int i = 0; i < sz; i += 2) {
            if (last[i] == -1) {
                if (last[i + 1] == -1) {
                    cur.push_back(-1);
                    ans *= 2;
                    ans %= mod;
                } else if (last[i + 1] <= sz / 2) {
                    cur.push_back(last[i + 1]);
                } else {
                    --count;
                    cur.push_back(-1);
                }
            } else if (last[i] <= sz / 2) {
                if (last[i + 1] == -1) {
                    cur.push_back(last[i]);
                } else if (last[i + 1] <= sz / 2) {
                    ans = 0;
                    return;
                } else {
                    --count;
                    cur.push_back(last[i]);
                }
            } else {
                if (last[i + 1] == -1) {
                    cur.push_back(-1);
                    --count;
                } else if (last[i + 1] <= sz / 2) {
                    cur.push_back(last[i + 1]);
                    --count;
                } else {
                    ans = 0;
                    return;
                }
            }
        }
        last.clear();
        for (auto it : cur) last.push_back(it);
        cur.clear();
        sz = last.size();
        ans *= fac[count];
        ans %= mod;
    }

}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> k;
    n = 1 << k;
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % mod; 
    solve();
    std::cout << ans << '\n';
    return 0;
}
