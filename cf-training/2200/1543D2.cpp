#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <assert.h>
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
int add(int x, int y) {
    std::vector<int> a, b, c;
    while (x) {
        a.push_back(x % k);
        x /= k;
    }
    int sgn = 1;
    if (y < 0) {
        y = -y;
        sgn = -1;
    }
    while (y) {
        b.push_back(y % k * sgn);
        y /= k;
    }
    int sz = std::max(a.size(), b.size());
    int sz_a = a.size();
    while (sz_a < sz) a.push_back(0), ++sz_a;
    int sz_b = b.size();
    while (sz_b < sz) b.push_back(0), ++sz_b;
    for (int i = 0; i < sz; ++i) {
        c.push_back((a[i] + b[i] + k) % k);
    }
    int res = 0;
    for (int i = sz - 1; i >= 0; --i) res *= k, res += c[i];
    return res;
}
int ask(int x) {
    std::cout << x << std::endl;
    int res;
    std::cin >> res;
    return res;
}
int main() {
    #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> k;
        int cur = 0, sum = 0;
        for (int i = 1; i <= n; ++i) {
            if (ask(cur)) break;
            sum = add(cur, -sum);
            cur = add(sum, (i % 2 == 0 ? 1 : -1) * i);
        }
    }

    return 0;
}

// 15 : 35 - 16 : 30

/*
2
0 2
1 3
1 2
*/