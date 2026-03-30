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
const int maxn = 1e6 + 5;
const ll mod = 998244353;
std::string s;
ll sum[maxn];
ll pw[maxn];
int flag;
int n;
bool verify(int x, int y, int z) {
    std::vector<int> a(n + 1, 0), b(n + 1, 0), c(n + 1, 0), d(n + 1, 0);
    for (int i = x - 1, j = n; i >= 0; --i, --j) {
        a[j] = s[i] - '0';
    }
    for (int i = x + y - 1, j = n; i >= x; --i, --j) {
        b[j] = s[i] - '0';
    }
    for (int i = n - 1, j = n; i >= x + y; --i, --j) {
        c[j] = s[i] - '0';
    }
    for (int i = n; i >= 0; --i) {
        int cur = a[i] + b[i];
        d[i] += cur;
        if (i) d[i - 1] += d[i] / 10;
        d[i] %= 10;
        if (d[i] != c[i]) return false;
    }
    return true;
}
void guess(int x, int y, int z) {
    if (flag) return;
    if (x <= 0 || y <= 0) return;
    if (x >= 2 && s[0] == '0') return;
    if (y >= 2 && s[x] == '0') return;
    if (z >= 2 && s[x + y] == '0') return; 
    ll v3 = ((sum[n] - sum[n - z] * pw[z]) % mod + mod) % mod;
    ll v2 = ((sum[x + y] - sum[x] * pw[y]) % mod + mod) % mod;
    ll v1 = sum[x];
    if ((v1 + v2) % mod == v3) {
        if (verify(x, y, z)) {
            flag = 1;
            for (int i = 0; i < x; ++i) std::cout << s[i];
            std::cout << '+';
            for (int i = x; i < x + y; ++i) std::cout << s[i];
            std::cout << '=';
            for (int i = x + y; i < n; ++i) std::cout << s[i];
            std::cout << '\n';
        }
    }
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> s;
    pw[0] = 1;
    for (int i = 1; i <= s.size(); ++i) {
        pw[i] = pw[i - 1] * 10 % mod;
    }
    for (int i = 0; i < s.size(); ++i) {
        sum[i + 1] = s[i] - '0';
        if (i) sum[i + 1] += sum[i] * 10;
        sum[i + 1] %= mod;
    }

    n = s.size();

    for (int len = (n + 2) / 3; len <= n; ++len) {
        guess(len - 1, n - len * 2 + 1, len);
        guess(len, n - len * 2, len);
        guess(n - len * 2 + 1, len - 1, len);
        guess(n - len * 2, len, len);
    }

    return 0;
}
// 17 : 32 - 