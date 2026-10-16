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
const ll mod = 998244353;
int n, k;
std::string s, z, t;
ll f[maxn], pw[maxn];
ll solve(std::string s) {
    ll count[2] = {0, 0};
    for (int i = 0; i < n; ++i) {
        count[s[i] - '0'] += 1;
    }
    return count[1] * count[0];
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    pw[0] = 1;
    for (int i = 1; i <= 30; ++i) {
        pw[i] = pw[i - 1] * 2;
    }
    f[0] = 1;
    for (int i = 1; i <= 30; ++i) {
        f[i] = pw[i - 1] + 1 - f[i - 1];
    }
    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> k >> s >> z;
        t = s;
        for (int i = 0; i < n; ++i) {
            if (s[i] != z[i]) t[i] = '1';
            else t[i] = '0';
        }
        std::cout << solve(s) * f[k] + solve(z) * f[k] + solve(t) * (pw[k] + 1 - 2 * f[k]) << '\n';
    }

    return 0;
}
