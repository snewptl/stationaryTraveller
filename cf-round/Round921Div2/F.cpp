#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#define all(x) x.begin(), x.end()
typedef int64_t ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const ll mod = 999999893;
const int maxn = 2e5 + 5;
const double eps = 1e-10;
int N;
ll quickPow(ll x, ll y) {
    ll res = 1;
    x = (x % mod + mod) % mod;
    while (y) {
        if (y & 1)
            res *= x, res %= mod;
        x *= x, x %= mod;
        y /= 2;
    }
    return res;
}
ll inv(ll x) {
    return quickPow(x, mod - 2);
}
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> N;
        ll bottom = inv((1 - quickPow(2, N - 1) + mod) % mod);
        ll A, B;
        if (N == mod) {
            // 当 N == mod 时，会导致bottom为0，这时要换一种算法。
            bottom = inv((1 - quickPow(2, N / 2) + mod) % mod);
            A = (1 - 2 * bottom) % mod;
            B = bottom;
        } else if (N % 2) {
            A = (-quickPow(2, N / 2 + 1) - 1 - quickPow(2, N - 1) + mod * 2) %
                mod * bottom % mod;
            B = (quickPow(2, N / 2) + 1) % mod * bottom % mod;
        } else {
            A = (quickPow(2, N / 2) - 1 - quickPow(2, N - 1) + mod * 2) %
                mod * bottom % mod;
            B = (-quickPow(2, N / 2) + 1 + mod) % mod * bottom % mod;
        }
        ll res =
            (-B * inv(A * A % mod - 2 * B * B % mod) % mod + mod) % mod;
        std::cout << res << '\n';
    }

    return 0;
}
