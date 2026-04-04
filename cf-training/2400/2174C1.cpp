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
        for (int i = 1; i <= n; ++i) {
            if (i > 2) prefix[i % 2][i] += prefix[i % 2][i - 2];
            prefix[i % 2][i] += invpw[i];
            prefix[i % 2][i] %= p;
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
        ans *= qp(2, p - 2);
        ans %= p;
        for (int i = 1; i <= n; ++i) {
            ans -=  prefix[i % 2][i];
            ans = (ans + p) % p;
            ans += invpw[i / 2] * i % p;
            ans %= p;
        }
        std::cout << ans << '\n';
    }

    return 0;
}
