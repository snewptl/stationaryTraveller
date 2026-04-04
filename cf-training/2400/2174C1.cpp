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
ll n, m, p;
ll sum[maxn];
ll pw[maxn];
ll invpw[maxn];
ll prefix[2][maxn];
ll qp(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y & 1) res *= x, res %= p;
        x *= x, x %= p;
        y /= 2;
    }
    return res;
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
        std::cin >> n >> m >> p;
        pw[0] = 1;
        for (int i = 1; i <= n; ++i) {
            pw[i] = pw[i - 1] * m % p;
        }
        invpw[n] = qp(pw[n], p - 2);
        for (int i = n - 1; i >= 0; --i) {
            invpw[i] = invpw[i + 1] * m % p;
        }
        prefix[1][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 2; ++j) {
                prefix[j][i] = prefix[j][i - 1];
                prefix[j][i] += invpw[i];
                prefix[j][i] %= p;

            }
        }
        ll all_sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum[i] = (n - i + 1) * invpw[i / 2] % p;
            all_sum += sum[i], all_sum %= p;
        }
        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
            ll res = 0;
            res += all_sum * (n - i + 1) % p * invpw[i / 2] % p;
            ans += res;
            ans %= p;
        }
        for (int i = 1; i <= n; ++i) {
            ll delta = 0;
            delta -=  prefix[i % 2][i / 2] * invpw[i / 2] % p;
            delta -= (prefix[i % 2][i / 2] - invpw[i / 2]) % p * invpw[i / 2]  % p ;
            delta += invpw[i / 2] * ((i + 1) / 2 - 1) % p * 2 % p;
            delta += invpw[i / 2];
            delta = (delta % p + p) % p;
            delta *= (n - i + 1), delta %= p;
            ans = (ans + delta) % p;
        }
        std::cout << ans << '\n';
    }

    return 0;
}
