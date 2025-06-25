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
const int maxn = 1e5 + 5;
const ll mod = 998244353;
int n, m;
int count[maxn];
ll f[maxn], sum[maxn];
pii a[51];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int l, r;
        std::cin >> l >> r;
        a[i] = {l, r};
    }
    ll ans = 0;
    for (int gcd = 1; gcd <= m; ++gcd) {
        int delta = (gcd == 1 ? 1 : -count[gcd]);
        if (gcd != 1 && !delta) continue;
        int flag = 1, last = m / gcd;
        for (int i = 0; i <= last; ++i) sum[i] = 1;
        for (int i = 0; i <= last; ++i) f[i] = 0;
        for (int i = 1; i <= n; ++i) {
            int start = (a[i].first + gcd - 1) / gcd;
            int end = a[i].second / gcd;
            for (int j = 0; j <= last; ++j) {
                f[j] = 0;
                if (j >= start) f[j] = sum[j - start];
                if (j > end) f[j] -= sum[j - end - 1];
                f[j] = (f[j] + mod) % mod;
            }
            for (int j = 0; j <= last; ++j) {
                sum[j] = f[j];
                if (j) sum[j] += sum[j - 1];
                sum[j] %= mod;
            }
        }
        for (int i = gcd; i <= m; i += gcd) {
            count[i] += delta;
        }
        ans += sum[last] * delta % mod;
        ans %= mod;
    }
    std::cout << (ans + mod) % mod << '\n';

    return 0;
}
// 19 : 06 - 