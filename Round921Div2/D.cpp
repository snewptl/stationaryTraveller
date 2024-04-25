#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const ll mod = 1e9 + 7;
const int maxn = 2e5 + 5;
const double eps = 1e-10;
ll factorial[maxn];
ll n, m, k;
ll friendshipSum, N, K, invN;

ll quikPow(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y & 1)
            res *= x, res %= mod;
        x *= x, x %= mod;
        y >>= 1;
    }
    return res;
}

ll inv(ll x) {
    return quikPow(x, mod - 2);
}

ll C(int all, int select) {
    return factorial[all] * inv(factorial[select]) % mod *
           inv(factorial[all - select]) % mod;
}

void prepareArrays() {
    factorial[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        factorial[i] = factorial[i - 1] * i % mod;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    prepareArrays();

    int T = 1;
    cin >> T;
    while (T--) {
        cin >> n >> m >> k;
        N = n * (n - 1) / 2 % mod;
        K = k * (k - 1) / 2 % mod;
        invN = inv(N);
        friendshipSum = 0;
        for (int i = 1; i <= m; ++i) {
            int a, b, f;
            cin >> a >> b >> f;
            friendshipSum += f;
            friendshipSum %= mod;
        }
        ll first = friendshipSum * invN % mod * k % mod;
        ll second = 0;

        for (int i = 1; i <= k; ++i) {
            second += C(k, i) * quikPow(invN, i) % mod *
                      quikPow(1 - invN + mod, k - i) % mod *
                      (1ll * i * (i - 1) / 2 % mod) % mod;
            second %= mod;
        }
        second = second * m % mod;
        cout << (first + second) % mod << '\n';
    }

    return 0;
}