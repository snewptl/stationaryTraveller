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
ll A[14][14] = {
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
};
ll v[14] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 2, 1};
ll n, f1, f2, f3, c;
void mul(ll (&A)[14][14], ll (&B)[14][14]) {
    ll C[14][14];
    for (int i = 0; i < 14; ++i) {
        for (int j = 0; j < 14; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < 14; ++k) {
                C[i][j] += A[i][k] * B[k][j];
                C[i][j] %= (mod - 1);
            }
        }
    }
    for (int i = 0; i < 14; ++i) {
        for (int j = 0; j < 14; ++j) {
            A[i][j] = C[i][j];
        }
    }
}
void quick_pow(ll x) {
    ll res[14][14];
    memset(res, 0, sizeof(res));
    for (int i = 0; i < 14; ++i) res[i][i] = 1;
    while (x) {
        if (x & 1) {
            mul(res, A);
        }
        mul(A, A);
        x /= 2;
    } 
    ll new_v[14];
    for (int i = 0; i < 14; ++i) {
        ll cur = 0;
        for (int j = 0; j < 14; ++j) {
            cur += v[j] * res[i][j] % (mod - 1);
        }
        new_v[i] = cur;
    } 
    for (int i = 0; i < 14; ++i) {
        v[i] = new_v[i];
    }
}
ll quick_pow(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y & 1) res *= x, res %= mod;
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

    int T = 1;
    // std::cin >> T;
    while (T--) {
        std::cin >> n >> f1 >> f2 >> f3 >> c;
        quick_pow(n - 3);
        ll fin = 1;
        fin = quick_pow(f1, v[8]) * quick_pow(f2, v[9]) % mod * quick_pow(f3, v[10]) % mod * quick_pow(c, v[11]) % mod;
        std::cout << fin << '\n'; 
    }

    return 0;
}
// 16 : 06 - 