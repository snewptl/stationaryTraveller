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
int a[maxn];
int k;
int count[2];
ll A[101][101], fin[101][101];
ll v[101];
void mul(ll (&A)[101][101], ll (&B)[101][101]) {
    ll C[101][101];
    for (int i = 0; i <= count[0]; ++i) {
        for (int j = 0; j <= count[0]; ++j) {
            C[i][j] = 0;
            for (int k = 0; k <= count[0]; ++k) {
                C[i][j] += A[i][k] * B[k][j] % mod;
                C[i][j] %= mod;
            }
        }
    }
    for (int i = 0; i <= count[0]; ++i) {
        for (int j = 0; j <= count[0]; ++j) {
            A[i][j] = C[i][j];
        }
    }
}
ll quick_pow(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y & 1) {
            res *= x, res %= mod;
        }
        x *= x, x %= mod;
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

    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        count[a[i]] += 1;
    }
    int diff = 0;
    for (int i = 1; i <= count[0]; ++i) {
        if (a[i] != 0) ++diff;
    }
    v[diff] = 1;
    ll inv = quick_pow(1ll * n * (n - 1) / 2 % mod, mod - 2);
    if (count[0] > count[1]) std::swap(count[0], count[1]);
    for (int i = 0; i <= count[0]; ++i) {
        if (i < count[0]) {
            A[i + 1][i] = 1ll * (count[0] - i) * (count[1] - i) % mod * inv;
            if (i > 0) {
                A[i - 1][i] = 1ll * i * i % mod * inv;
                A[i][i] = 1 - A[i - 1][i] - A[i + 1][i];
            } else {
                A[i][i] = 1 - A[i + 1][i];
            }
        } else {
            if (i > 0) {
                A[i - 1][i] = 1ll * i * i % mod * inv;
                A[i][i] = 1 - A[i - 1][i];
            } else {
                A[i][i] = 1;
            }
        }
    }
    for (int i = 0; i <= count[0]; ++i) {
        for (int j = 0; j <= count[0]; ++j) {
            A[i][j] = (A[i][j] % mod + mod) % mod;
        }
    }
    for (int i = 0; i <= count[0]; ++i) fin[i][i] = 1;
    while (k) {
        if (k & 1) {
            mul(fin, A);
        }
        mul(A, A);
        k /= 2;
    }
    ll ans = 0;
    for (int i = 0; i <= count[0]; ++i) {
        ans += fin[0][i] * v[i] % mod;
        ans %= mod;
    }
    std::cout << ans << '\n';

    return 0;
}  
// 20 : 00 - 