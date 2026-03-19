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
const ll mod = 1e9 + 7;
int n;
ll ans;
ll a[maxn];
ll prefix[maxn];
int pre[maxn];
ll cal[maxn];
ll sum_fac[maxn], fac[maxn];
std::map<int, int> mp;
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        if (a[i] == a[i - 1]) {
            pre[i] = pre[i - 1];
        } else {
            pre[i] = i - 1;
        }
        mp[a[i]] += 1;
    }
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = fac[i - 1] * i % mod;
    } 
    sum_fac[0] = 1;
    for (int i = 1; i < n; ++i) {
        sum_fac[i] = sum_fac[i - 1] * i % mod + 1;
        sum_fac[i] %= mod;
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] == a[i - 1]) continue;
        if (a[i] != a[n]) {
            ans += sum_fac[pre[i]] * fac[n - i] % mod * a[i] % mod * mp[a[i]] % mod;
            ans %= mod;
        }
    }
    std::cout << ans << '\n';

    return 0;
}
// 15 : 20 - 